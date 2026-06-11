#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;


signed main(void){
    int n;
    scanf("%lld", &n);
    vector <int> a;
    int mae=0;
    int cnt = 0;
    rep(i,n){
        int c; scanf("%lld", &c);
        if(mae==c) continue;
        else {a.push_back(c); mae = c; cnt++;}
    }
    n = cnt;
    vector <int> dp(200005), dp2(200005,0); dp[0] = 1;
    vector <vector<int>> rock(200005,vector <int>());
    
    for(int i=0;i<n;i++){
        dp[i+1] = dp[i];
        int x = rock[a[i]].size();
        dp[i+1] += dp2[a[i]];
        dp2[a[i]] += dp[i];
        dp[i+1]%=MOD;
        rock[a[i]].push_back(i);
    }
    printf("%lld", dp[n]%MOD);
}
