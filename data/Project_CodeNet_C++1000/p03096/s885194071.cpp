#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N;
    cin >> N;
    vector<int> c(N);
    rep(i,N) cin >> c[i];
    vector<int> color(200005,-1);
    vector<ll> dp(N+1,0);
    dp[0] = 1;
    rep(i,N){
        if(color[c[i]] == -1){
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
            color[c[i]] = i+1;
        }
        else{
            if(color[c[i]] != i){ 
                dp[i+1] += dp[color[c[i]]] + dp[i];
            }
            else dp[i+1] = dp[i];
            dp[i + 1] %= MOD;
            color[c[i]] = i+1;
        }
    }
    cout << dp[N] << endl;
}