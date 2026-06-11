#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
bool chmin(ll& a, ll& b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll& a, ll& b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main(){
    string S,S1;
    cin >> n;
    r = n - 1;
    l = 0;
    cout << r << endl;
    cin >> S;
    if (S[0] == 'V')return 0;
    cout << l << endl;
    cin >> S;
    if (S[0] == 'V')return 0;
    S1 = S;
    t = 0;
    while (1) {
        x = (l + r) / 2;
        cout << x << endl;
        cin >> S;
        if (S[0] == 'V')return 0;
        if (((x - l) % 2 == 0) ^ (S[0] == S1[0]))r = x;
        else{
          l = x;
          S1=S;
        }
    }
}
