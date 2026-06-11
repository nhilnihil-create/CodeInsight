#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    ll n,m;
    cin >> n >> m;
    ll teisyutu = 1LL << m;
    ll x = 1900 * m + 100 * ( n - m);
    cout << x * teisyutu << endl;
    return 0;
}