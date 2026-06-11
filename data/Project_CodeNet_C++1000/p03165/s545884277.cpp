#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    vvl dp(n+1, vl(m+1));  // dp[i][j] : sのi文字目までとtのj文字目までのLCSの長さ
    rep(i, n) {
        rep(j, m) {
            chmax(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
            if(s[i] == t[j]) {
                chmax(dp[i+1][j+1], dp[i][j] + 1);
            }
        }
    }

    string ans = "";
    ll i = n-1, j = m-1;
    while(i >= 0 && j >= 0) {
        if(dp[i+1][j+1] == dp[i][j] + 1 && s[i] == t[j]) {
            ans = s[i] + ans;
            i--;  j--;
        }
        else if(dp[i+1][j+1] == dp[i][j+1]) {
            i--;
        }
        else if(dp[i+1][j+1] == dp[i+1][j]) {
            j--;
        }
    }
    
    out(ans);
    re0;
}
