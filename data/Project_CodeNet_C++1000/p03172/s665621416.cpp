#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-9
#define f first
#define s second
#define ll long long
#define read(x) scanf("%d", &x)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
using namespace std;

int main(){
    //freopen("test.txt", "r", stdin);
    IO;
    int n, K;
    cin >> n >> K;
    vector<int> v(n);
    vector<int> dp(K + 1);
    vector<int> prefix(K + 1, 1);
    for(int &a : v)
        cin >> a;
    dp[0] = 1;
    for(int child : v){
        for(int k = 1; k <= K; ++k){
            dp[k] = prefix[k];
            if(k - child - 1 < 0)
                continue;
            dp[k] -= prefix[k - child - 1];
            if(dp[k] < 0)
                dp[k] += MOD;
        }
        for(int k = 1; k <= K; ++k)
            prefix[k] = (dp[k] + prefix[k - 1]) % MOD;
    }
    cout << dp[K];
}
