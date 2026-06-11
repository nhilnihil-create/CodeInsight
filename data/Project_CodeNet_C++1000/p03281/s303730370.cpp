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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i%j == 0) cnt++;
        }
        if (cnt == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}