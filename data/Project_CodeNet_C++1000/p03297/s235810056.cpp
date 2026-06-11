#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b > a || b > d){
            cout << "No" << endl;
            continue;
        }
        ll g = gcd(b, d);
        a = a + d * (c / d + 1);
        a = c + (a - c) % g;
        if(a == c) a += g;
        if(b > a) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
