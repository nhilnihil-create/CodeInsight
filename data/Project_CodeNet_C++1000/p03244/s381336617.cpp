#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;
const int n_max=1e+5;
int main(){
    int n,tmp;
    cin >> n;
    vector<int> v_o(n_max+1,0),v_e(n_max+1,0);
    rep(i,n){
        cin >> tmp;
        if(i%2==0) v_e[tmp]++;
        if(i%2!=0) v_o[tmp]++;
    }
    int max_e=0;
    int second_e=0;
    int max_o=0;
    int second_o=0;
    int i_o=0;
    int i_e=0;
    rep(i,n_max+1){
        if(max_o<=v_o[i]){
            max_o=v_o[i];
            i_o=i;
        }
        if(max_e<=v_e[i]){
            max_e=v_e[i];
            i_e=i;
        }
    }

    rep(i,n_max+1){
        if(second_o<=v_o[i]&&i!=i_o){
            second_o=v_o[i];
        }
        if(second_e<=v_e[i]&&i!=i_e){
            second_e=v_e[i];
        }
    }

    if(i_e==i_o){
        cout << (n-max_o-max(second_o,second_e)) << endl; 
    }else{
        cout << (n-max_o-max_e) << endl;
    }
    
}
