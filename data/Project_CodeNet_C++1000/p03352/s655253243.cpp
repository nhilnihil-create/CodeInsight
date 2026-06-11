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
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1; i <= 33; i++) {
        for (int j = i*i; j <= x; j *= i) {
            ans = max(ans, j);
            if (j == 1) break;
        }
    }
    cout << ans << endl;
    return 0;
}