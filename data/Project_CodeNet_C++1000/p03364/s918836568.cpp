#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }


int main() {
    int n;
    cin >> n;
    
    string s[n];
    rep(i, n) cin >> s[i];
    
    int c = 0;
    rep(b, n) {
        string t[n];
        rep(k, n) rep(l, n) { // tのk, l番目
            t[k] += s[k][(l + b) % n];
            if (k > l) {
                if (t[k][l] != t[l][k]) {
                    goto nxt;
                }
            }
        }
        c += n;
    nxt:
        continue;
    }
    cout << c << '\n';
}
