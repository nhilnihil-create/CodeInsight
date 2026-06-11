#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;

    if ((b-a+1)<(k*2)) {
        for (ll i=a; i<=b; i++) {
            cout << i << endl;
        }
        return 0;
    }
    for (ll i=a; i<a+k; i++) {
        cout << i << endl;
    }
    for (ll i=b-k+1; i<=b; i++) {
        cout << i << endl;
    }

    return 0;
}