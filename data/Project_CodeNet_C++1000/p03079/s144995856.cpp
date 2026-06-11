#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int a, b, c;

int main()
{
    cin >> a >> b >> c;
    if (a == b && b == c && c == a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
