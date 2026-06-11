//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll mi = min({a, b, c, d, e});
    cout << 4+(n+mi-1)/mi << endl;
}