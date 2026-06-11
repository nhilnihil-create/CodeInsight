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
    int n = s.size();
    string ans = "AC";
    if (s[0] != 'A') {
        ans = "WA";
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (isupper(s[i])) {
            if (i == 1 || i == n-1 || s[i] != 'C') {
                ans = "WA";
            }
            cnt++;
        }
    }
    if (cnt != 1) ans = "WA";
    cout << ans << endl;
    return 0;
}