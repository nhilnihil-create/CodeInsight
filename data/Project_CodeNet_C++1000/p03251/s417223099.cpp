#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(all(a)), sort(all(b));

    bool is_war = true;
    for(int c = a.back()+1; c <= b[0]; c++){
        if(x < c && c < y) is_war = false;
    }
    if(is_war) cout << "War" << ln;
    else cout << "No War" << ln;
}


