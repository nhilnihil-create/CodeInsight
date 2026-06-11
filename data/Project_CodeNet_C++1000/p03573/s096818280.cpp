#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a == b)cout << c << endl;
    else if(b == c)cout << a << endl;
    else if(a == c)cout << b << endl;
    return 0;
}