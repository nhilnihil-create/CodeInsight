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

string f(int x) {
    string res;
    int keta = 0;
    int ix = x;
    while (ix > 0) {
        keta++;
        ix /= 10;
    }
    int z = 6-keta;
    rep(i,z) res += '0';
    res += to_string(x);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(m);
    vector<vector<P>> t(n);
    rep(i,m) {
        int p, y;
        cin >> p >> y;
        s[i] += f(p);
        p--;
        t[p].emplace_back(y,i);
    }
    rep(i,n) {
        sort(t[i].begin(), t[i].end());
    }
    rep(i,n) {
        rep(j,t[i].size()) {
            int id = t[i][j].second;
            s[id] += f(j+1);
        }
    }
    rep(i,m) {
        cout << s[i] << endl;
    }
    return 0;
}