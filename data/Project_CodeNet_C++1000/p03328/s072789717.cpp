#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int a,b;
    cin >> a >> b;
    int ans = 0;
    rep(i,b - a) {
        ans += i;
    }
    cout << ans - a << endl;
}

