#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N;
    cin >> N;
    int C[N];
    rep(i, N) cin >> C[i];
    ll dp[N];
    map<int, int> mp;
    vector<int> vec[N];
    dp[0] = 1;
    mp[C[0]] = 0;
    vec[0].push_back(0);
    rep2(i, 1, N){
        if(C[i] == C[i-1]) dp[i] = dp[i-1];
        elif(!mp.count(C[i])){
            dp[i] = dp[i-1];
            mp[C[i]] = i;
            vec[i].push_back(i);
        }
        else{
            dp[i] = dp[i-1];
            int j = mp[C[i]];
            int k = vec[j].size()-1;
            dp[i] += dp[vec[j][k]];
            dp[i] %= MOD;
            vec[j].push_back(i);
        }
    }
    cout << dp[N-1] << endl;
}