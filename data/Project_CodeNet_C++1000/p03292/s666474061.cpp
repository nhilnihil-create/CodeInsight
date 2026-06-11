#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int mx = max({a, b, c});
    int mn = min({a, b, c});
    int ans = mx - mn;
    cout << ans << endl;
    return 0;
}