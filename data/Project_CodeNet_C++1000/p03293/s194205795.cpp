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
    string s, t;
    cin >> s >> t;
    string a = s;
    a += s;
    int n = s.size();
    string ans = "No";
    rep(i,n) {
        string now;
        rep(j,n) now += a[i+j];
        if (now == t) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}