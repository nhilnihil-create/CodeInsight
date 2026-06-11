#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if((b - a) % 2 == 0) cout << "Alice" << endl;
    else cout << "Borys" << endl;
    return 0;
}