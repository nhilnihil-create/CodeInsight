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
    string s;
    cin >> s;
    ll n = s.size();

    string x = "keyence";

    if(s == x) {
        out("YES");
        re0;
    }

    if(s.substr(0, 7) == x) {
        out("YES");
        re0;
    }

    if(s.substr(n-7, 7) == x) {
        out("YES");
        re0;
    }

    exrep(j, 1, n-2) {
        exrep(k, 1, min((n-1)-j, n-7)) {
            string mae = s.substr(0, j);
            string ushiro = s.substr(j+k, n -(j+k));
            if(mae + ushiro == x) {
                out("YES");
                re0;
            }
        }
    }
    
    out("NO");    
    re0;
}