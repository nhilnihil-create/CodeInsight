#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
int a, b, c;

signed main()
{
    cin >> a >> b >> c;
    c = min(c, a + b + 1);
    cout << b + c << endl;
}
