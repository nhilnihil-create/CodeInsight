#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a + b == 15)
        cout << "+" << endl;
    else if (a * b == 15)
        cout << "*" << endl;
    else
        cout << "x" << endl;
    return 0;
}
