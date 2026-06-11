#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll A, B;
    cin >> A >> B ;
    cout << (1900 * B + 100 * (A - B)) * pow(2 , B) << endl;
    
}
