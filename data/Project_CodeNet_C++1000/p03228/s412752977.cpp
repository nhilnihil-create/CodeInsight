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
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pair<ll, ll>>> vvpll;
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
    ll a, b, k;
    cin >> a >> b >> k;
    ll taka = a, aoki = b;
    rep(i, k) {
        if(i%2 == 0) {
            if(taka%2 == 1) {
                taka--;
            }
            aoki += taka/2;
            taka /= 2;
        }
        else {
            if(aoki%2 == 1) {
                aoki--;
            }
            taka += aoki/2;
            aoki /= 2;
        }
    }

    cout << taka << " " << aoki << endl;
    re0;
}