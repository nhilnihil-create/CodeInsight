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
    for(int i = 0; i < t; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b > d || b > a){
            cout << "No" << endl;
            continue;
        }
        if(c > b){
            cout << "Yes" << endl;
            continue;
        }
        ll g = gcd(b, d);
        if(((a - b) / g + 1) * g < a - c) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}