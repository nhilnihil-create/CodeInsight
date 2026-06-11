#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    map<int,int> a;
    map<int,int> b;
    rep(i, n) {
        int v;
        cin >> v;
        if(i%2) a[v]++;
        else b[v]++;
    }
    int af = 0;
    int as = 0;
    int ai = 0;
    for(auto x : a) {
        if(x.second >= af) {
            as = af;
            af = x.second;
            ai = x.first;
        }
        else if(x.second >= as) {
            as = x.second;
        }
    }
    int bf = 0;
    int bs = 0;
    int bi = 0;
    for(auto x : b) {
        if(x.second >= bf) {
            bs = bf;
            bf = x.second;
            bi = x.first;
        }
        else if(x.second >= bs) {
            bs = x.second;
        }
    }
    if(ai == bi) {
        int ans = min(n - (af + bs),n - (as + bf));
        cout << ans << endl;
    }
    else cout << n - af - bf << endl;
    return 0;
}
