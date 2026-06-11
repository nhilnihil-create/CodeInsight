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
    int n, k;
    cin >> n >> k;
    n -= k;
    int ans = 1;
    if (n <= 0) {
        cout << ans << endl;
        return 0;
    }
    ans += (n+k-1-1)/(k-1);
    cout << ans << endl;
    return 0;
}