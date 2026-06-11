#include <bits/stdc++.h>
using namespace std ;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll ;
typedef long double ld ;

const ll MOD = 1e9 + 7 ;
const double PI = 2 * acos(0.0) ;
const long double EPS = 1.0E-14 ;

int main()
{
    ll a, b, c ;
    cin >> a >> b >> c ;
    if (a + b >= c) cout << "Yes" ;
    else    cout << "No" ;

    return 0 ;
}
