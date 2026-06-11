#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    int N;
    string s;
    cin >> N >> s;

    const ll MOD = 1e9+7;
    Vvec<ll> dp(N, vector<ll>(N));
    dp[0][0] = 1;
    // dp[i][j] = dp[i-1][0] + ... + dp[i-1][j-1] <
    // dp[i][j] = dp[i-1][j] + ... + dp[i-1][i-1] >
    for(int i=1; i<N; i++){
        if(s[i-1]=='<'){
            dp[i][0] = 0;
            for(int j=1; j<=i; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                dp[i][j] %= MOD;
            }
        }
        else{
            dp[i][i] = 0;
            for(int j=i-1; j>=0; j--){
                dp[i][j] = dp[i][j+1] + dp[i-1][j];
                dp[i][j] %= MOD; 
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<N; i++){
        ans += dp[N-1][i];
        ans %= MOD;
    }
    cout << ans << endl;
}