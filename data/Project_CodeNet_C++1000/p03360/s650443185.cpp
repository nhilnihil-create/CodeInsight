#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    ll d = max(a,max(b,c));
    rep(i,k) {
        d *= 2;
    }
    cout << a + b + c + d - max(a,max(b,c)) << endl;
}

