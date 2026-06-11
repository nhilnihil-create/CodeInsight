#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
const ll MAX_N = 100010;
 
int main() {
    ll n;
    cin >> n;

    ll ans = 0, cntA = 0, Bcnt = 0, BcntA = 0;
    rep(loop, n) {
        string s;
        cin >> s;
        ll m = s.size();
        rep(i, m-1) {
            if(s[i] == 'A' && s[i+1] == 'B') {
                ans++;
            }
        }
        if(s[0] == 'B' && s[m-1] == 'A') {
            BcntA++;
            continue;
        }
        if(s[0] == 'B') {
            Bcnt++;
        }
        if(s[m-1] == 'A') {
            cntA++;
        }
    }

    if(BcntA == 0) {
        ans += min(Bcnt, cntA);
        out(ans);
        re0;
    }

    ans += BcntA - 1;
    if(Bcnt > 0) {
        ans++;
        Bcnt--;
    }
    if(cntA > 0) {
        ans++;
        cntA--;
    }
    
    ans += min(Bcnt, cntA);
    out(ans);
    re0;
}