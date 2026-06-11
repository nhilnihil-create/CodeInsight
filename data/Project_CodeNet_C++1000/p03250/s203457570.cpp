#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(), v.end()
#define dcout cout << fixed << setprecision(15)
#define arep(i, a) for(auto i : a)
#define F first
#define S second
#define VE vector<int>
#define pb(x) push_back(x)
#define MOD 1000000007
#define INF 10000000000
#define int long long
#define KETA(n) floor(log10(n) + 1)
using namespace std;
signed main() {
    VE v;
    int a, b, c;
    cin >> a >> b >> c;
    v.pb(a);
    v.pb(b);
    v.pb(c);
    sort(all(v));
    cout << v[2] * 10 + v[0] + v[1];
    return 0;
}