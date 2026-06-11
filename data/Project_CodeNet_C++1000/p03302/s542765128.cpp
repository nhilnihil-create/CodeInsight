#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a + b == 15) cout << "+" << endl;
    else if(a * b == 15) cout << "*" << endl;
    else cout << "x" << endl;
    return 0;
}