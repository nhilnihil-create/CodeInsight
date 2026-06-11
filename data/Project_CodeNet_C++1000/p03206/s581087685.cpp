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
    int d;
    cin >> d;
    string ans;
    if (d == 25) ans = "Christmas";
    if (d == 24) ans = "Christmas Eve";
    if (d == 23) ans = "Christmas Eve Eve";
    if (d == 22) ans = "Christmas Eve Eve Eve";
    cout << ans << endl;
    return 0;
}