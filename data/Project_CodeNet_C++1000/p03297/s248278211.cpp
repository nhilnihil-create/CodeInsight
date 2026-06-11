#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ll t, a, b, c, d;

    cin >> t;

    while(t--) {

        cin >> a >> b >> c >> d;

        ll gcd = 0, ans = 0;

        if(b > a || b > d) cout << "No" << endl;

        else if(c >= b) cout << "Yes" << endl;

        else {

            gcd = __gcd(b, d);

            ll mod = a % gcd;

            ans = b + mod - gcd;

            //cout << gcd << endl;

            if(ans > c) cout << "No" << endl;
            else cout << "Yes" << endl;

        }
    }
}
