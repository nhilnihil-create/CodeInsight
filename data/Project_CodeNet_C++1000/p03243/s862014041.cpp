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
    string s;
    cin >> s;
    int x = 0;
    rep(i,3) {
        if (s[i]-'0' > x) {
            if (i == 0) x = s[i]-'0';
          	else x++;
            if (i != 0) break;
        }
        else if (s[i]-'0' < x) break;
    }
    int ans = 100*x + 10*x + x;
    cout << ans << endl;
    return 0;
}