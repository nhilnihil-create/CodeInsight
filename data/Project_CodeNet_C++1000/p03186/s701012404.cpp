#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(c <= a + b + 1) cout << b + c << endl;
    else cout << a + b + 1 + b << endl;
    return 0;
}