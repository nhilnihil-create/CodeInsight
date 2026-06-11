#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<P> before;
    vector<P> after;
    int n = 0;
    rep(i, h) rep(j, w) {
        if (j==w-1) {
            if (i==h-1) continue;
            if (a[i][j]%2==1) {
                a[i][j]--;
                a[i+1][j]++;
                before.emplace_back(i, j);
                after.emplace_back(i+1, j);
            }
        }
        else {
            if (a[i][j]%2==1) {
                a[i][j]--;
                a[i][j+1]++;
                before.emplace_back(i, j);
                after.emplace_back(i, j+1);
            }
        }
    }
    n = before.size();
    cout << n << endl;
    rep(i, n) {
        cout << before[i].first+1 << " " << before[i].second+1 << " " << after[i].first+1 << " " << after[i].second+1 << endl;
    }
    
    return 0;
}
