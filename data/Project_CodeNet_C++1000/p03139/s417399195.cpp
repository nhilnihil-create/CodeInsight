#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(a > b) cout << b;
    else cout << a;
    cout << " ";
    if(a + b - n > 0) cout << a + b - n;
    else cout << 0;
    cout << endl; 
    return 0;
}