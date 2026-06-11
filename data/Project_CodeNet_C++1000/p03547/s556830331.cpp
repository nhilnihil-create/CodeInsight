#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    char x,y;
    cin >> x >> y;
    cout << (x > y? '>':x == y? '=' : '<') << endl;
    return 0;
}