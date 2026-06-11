#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;

ll dp[50][2];
int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll count;
    rep(i, 50)rep(j, 2) dp[i][j] = -1;
    dp[45][0] = 0;

    for(int i = 44; i >= 0; i--){
        count = 0;
        rep(j, n){
            if((a[j] >> i) % 2) count++;
        }

        if(dp[i + 1][1] >= 0){
            dp[i][1] = max(dp[i][1], dp[i + 1][1] + (1LL << i) * max(count, n - count));
        }
        if(dp[i + 1][0] >= 0){
            if(k & (1LL << i)){
                dp[i][1] = max(dp[i][1], dp[i + 1][0] + (1LL << i) * count);
                dp[i][0] = max(dp[i][0], dp[i + 1][0] + (1LL << i) * (n - count));
            }else{
                dp[i][0] = max(dp[i][0], dp[i + 1][0] + (1LL << i) * count);
            }
        }    
    }
    cout << max(dp[0][0], dp[0][1]) << endl;
}