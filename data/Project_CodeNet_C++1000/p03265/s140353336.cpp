#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
using ll = long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3 = x2 - (y2 - y1);
    int y3 = y2 + (x2 - x1);
    int x4 = x3 - (x2 - x1);
    int y4 = y3 - (y2 - y1);
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    return 0;
}