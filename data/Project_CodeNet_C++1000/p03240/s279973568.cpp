#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll N;
    cin >> N;
    ll dp[N][3];
    ll tmpx,tmpy,tmph;
    
    for(ll i = 0; i < N; i++){
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        if(dp[i][2] != 0){
            tmpx = dp[i][0];
            tmpy = dp[i][1];
            tmph = dp[i][2];
        }
    }

    ll ansx = -1;
    ll ansy = -1;
    ll ansh = -1;
    for(ll x = 0; x <= 100; x++){
        for(ll y = 0; y <= 100; y++){
            ll H = abs(x - tmpx) + abs(y - tmpy) + tmph;
            bool flg = true;
            for(ll k = 0; k < N; k++){
                ll tmp = H - abs(x - dp[k][0]) - abs(y - dp[k][1]);
                if(tmp <= 0) tmp = 0;
                if(tmp == dp[k][2]){
                    continue;
                } else { 
                    flg = false;
                    break;
                }
            }
            if(flg){
                ansx = x; 
                ansy = y;
                ansh = H;
                break;
            } else { 
                continue;
            }
        }
    }
    cout << ansx << " " << ansy << " " << ansh << endl;

}
