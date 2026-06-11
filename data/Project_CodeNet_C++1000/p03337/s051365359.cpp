#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main()
{
    int a, b;
    cin >> a >> b;
    int x = max(a + b, a - b);
    x = max(x, a * b);
    cout << x << endl;
    return 0;
}
