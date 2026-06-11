#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    int L,R;
    L=0;
    R=0;
    rep(i,N){
        if(S[i]=='E'){
            R++;
        }else{
            L++;
        }
    }

    int l_i,r_i;
    l_i=0;
    r_i=0;
    int tmp_l,tmp_r;
    tmp_l=0;
    tmp_r=0;
    int ans=INF;
    rep(i,N){
        tmp_l=l_i;
        tmp_r=r_i;
        if(S[i]=='E'){
            r_i++;
        }else{
            l_i++;
        }
        ans = min(ans,tmp_l+R-r_i);
    }
    cout << ans << endl;

}
