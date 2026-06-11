
#include<bits/stdc++.h>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;

using ll = long long;


ll a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r;
string s, t, u;
ll v, w, x, y, z;

int main() {

    cin >> n >> s >> t >> u;
    rep(i, n) {
        set<char> z{ s[i], t[i], u[i] };
        r += z.size() - 1;
    }
    cout << r << endl;


}