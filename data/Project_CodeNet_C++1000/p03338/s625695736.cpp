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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int now = 0;
        set<char> a;
        rep(j,i) a.insert(s[j]);
        for (int k = i; k < n; k++) {
            if (a.count(s[k])) {
                now++;
                a.erase(s[k]);
            }
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}