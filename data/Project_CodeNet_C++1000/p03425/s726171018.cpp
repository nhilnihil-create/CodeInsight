#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

const int N_MAX = 3010;



int main() {
    int N; cin >> N;
    int m = 0;
    int a = 0;
    int r = 0;
    int c = 0;
    int h = 0;
    rp(i, 0, N) {
        string s;
        cin >> s;
        if(s[0] == 'M') m++;
        if(s[0] == 'A') a++;
        if(s[0] == 'R') r++;
        if(s[0] == 'C') c++;
        if(s[0] == 'H') h++;
    }
    ll res = 0;
    res += (ll) m * a * (r+c+h);
    res += (ll) m * r * (c+h);
    res += (ll) m * c * h;
    res += (ll) a * r * (c+h);
    res += (ll) a * c * h;
    res += (ll) r * c * h;
    cout << res << endl;
    return 0;
}