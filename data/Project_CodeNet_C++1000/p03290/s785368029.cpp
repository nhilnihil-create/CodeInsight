#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
int dp[1100][5500];
int p[11],c[11];
signed main(){
    int d,g;cin >> d >> g;
    rep(i,d)cin >> p[i] >> c[i];
    int ans = 1001001001001ll;
    rep(perf,1<<d){
        int score = 0;
        int solve = 0;
        rep(i,d){
            if(perf>>i&1){
                score += (p[i]*100*(i+1))+ c[i];
                solve += p[i];
            }

        }
        //cout << solve <<" " <<  score << endl;
        for(int i = d-1;i >= 0 ; i--){
            if(perf>>i&1)continue;
            if(score + (p[i]-1)*100*(i+1) >= g){
                int rest = max(0ll,g-score);
                int onep = 100*(i+1);
                solve += (rest+onep-1)/onep;
                score += solve*100*(i+1);
                break;

            }
          
            else {
                solve += p[i]-1;
                score += (p[i]-1)*100*(i+1);    

            }
            
        }
        if(score >= g)ans = min(ans,solve);
        //cout << solve << " " << score << endl;
    }
    
    cout << ans << endl;
    

    return 0;
}