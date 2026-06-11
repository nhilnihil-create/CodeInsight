#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int INF = 1e9;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    map<ll, int> mp;
    VI dp(n+1, INF);
    mp[0] = 0;
    dp[0] = 0;
    int mask = 0;
    REP(i,n){
        int x = s[i] - 'a';
        mask ^= (1 << x);
        REP(j,26){
            if (mp.count(mask ^ (1 << j))){
                dp[i+1] = min(dp[i+1], dp[mp[mask ^ (1 << j)]] + 1);
            }
        }
        if (mp.count(mask)){
            dp[i+1] = min(dp[i+1], dp[mp[mask]] + 1);
        }
        if (mp.count(mask) == 0 || (mp.count(mask) > 0 && dp[mp[mask]] > dp[i+1])){
            mp[mask] = i + 1;
        }
    }
    cout << dp[n] << endl;

    // REP(i,n+1) cout << dp[i] << " ";
    // cout << endl;

    return 0;
}
