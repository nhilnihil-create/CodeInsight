//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int64_t gcd(int64_t a, int64_t b) {return b?gcd(b, a%b):a;}
int64_t lcm(int64_t a, int64_t b) {return a/gcd(a,b)*b;}
int64_t extgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) { // ax+by=gcd(a, b)の解を与える
    int64_t d = a;
    if(b) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int mm = gcd(n, m);
    rep(i, mm) {
        if(s[n/mm*i] != t[m/mm*i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << lcm((ll)n, m) << endl;
}