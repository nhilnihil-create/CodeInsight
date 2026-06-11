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
    int k;
    cin >> k;
    vector<string> d;
    int n = s.size();
    rep(i,n) {
        string tmp;
        rep(j,k) {
            if (i+j >= n) break;
            tmp += s[i+j];
            d.push_back(tmp);
        }
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    string ans = d[k-1];
    cout << ans << endl;
    return 0;
}