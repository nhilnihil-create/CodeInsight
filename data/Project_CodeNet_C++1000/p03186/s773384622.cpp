#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (c <= a + b)
        cout << c + b << endl;
    else
        cout << a + b + b + 1 << endl;
}