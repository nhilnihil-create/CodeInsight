#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, d;
    cin >> n >> m >> d;
    if(d != 0) cout << fixed << setprecision(15) << (n - d) * 2.0 * (m - 1) / (n * n) << endl;
    else cout << fixed << setprecision(15) << (n - d) * 1.0 * (m - 1) / (n * n) << endl;
}