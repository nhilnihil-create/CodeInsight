#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll gcd(ll x, ll y) {

    if(y == 0) {
        return x;
    }
    
    return gcd(y, x%y);
}

int main() {
    int T;
    cin >> T;

    rep(i, T) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if(b > a || b > d) {
            cout << "No" << "\n";
            continue;
        }

        if(c >= b) {
            cout << "Yes" << "\n";
            continue;
        }

        ll g = gcd(b, d);
        ll e = b - g + a%g;

        if(e > c) {
            cout << "No";
        }
        else {
            cout << "Yes";
        }
        cout << "\n";
    }

    return 0;
}