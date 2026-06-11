#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll l = n*m/gcd(n, m);

    ll p = l/n;
    ll q = l/m;
    ll r = p*q/gcd(p, q);
    for(ll i = 0; i < l; i+=r) {
        if(!(s.at(i/p) == t.at(i/q))) {
            cout << -1 << endl;
            return 0;
        }
    }
    //
    cout << setprecision(20) << l << endl;
    return 0;
}