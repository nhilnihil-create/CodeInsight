#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(n%2)cout << "Hello World" << endl;
    else cout << a+b << endl;
    return 0;
}