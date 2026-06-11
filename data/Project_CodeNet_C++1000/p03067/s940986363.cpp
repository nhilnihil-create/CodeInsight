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
    string ans = "No";
    if(c > a && b > c) ans = "Yes";
    if(c < a && b < c) ans = "Yes";
    cout << ans << endl;
    return 0;
}