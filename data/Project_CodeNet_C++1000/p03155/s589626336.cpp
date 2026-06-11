#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, h, w;
    cin >> n;
    cin >> h;
    cin >> w;
    cout << (n - h + 1) * (n - w + 1) << endl;
    return 0;
}