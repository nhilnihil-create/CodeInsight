#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<char> hum(N);
    
    int lE=0,lW=0,rE=0,rW=0;
    rep(i,N){
        cin >> hum[i];
        if(hum[i]=='E'){
            lE++;
        }else if(hum[i]=='W'){
            lW++;
        }
    }
    
    int ans=1'000'000;
    rep(i,N){
        //int ret_hum=0;
        
        if(hum[i]=='E'){
            lE--;
        }else if(hum[i]=='W'){
            lW--;
        }
        //振り向く人の計算
        ans = min(ans, lE + rW);
        
        //次の人の為に更新
        if(hum[i]=='E'){
            rE++;
        }else if(hum[i]=='W'){
            rW++;
        }
    }
    cout << ans << endl;
    
}
