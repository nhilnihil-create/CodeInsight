#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n;
    cin >> n;

    vector<LL> a(1<<n);
    for(int i = 0; i < 1<<n; i++){
        cin >> a[i];
    }

    vector<vector<LL>> dp(1<<n,vector<LL>(2,0));
    for(int i = 0; i < 1<<n; i++){
        dp[i][0] = a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1<<n; j++){
            if(j&(1 << i)){
                LL x = dp[j^(1<<i)][0];
                LL y = dp[j^(1<<i)][1];
                if(dp[j][0] < x){
                    LL tmp = dp[j][0];
                    dp[j][0] = x;
                    if(tmp < y){
                        dp[j][1] = y;
                    }else{
                        dp[j][1] = tmp;
                    }
                }else if(dp[j][1] < x){
                    dp[j][1] = x;
                }
            }
        }
    }

    LL ans = 0;

    for(int i = 1; i < 1<<n; i++){
        ans = max(ans,dp[i][0]+dp[i][1]);
        cout << ans << endl;
    }
    
    return 0;
}