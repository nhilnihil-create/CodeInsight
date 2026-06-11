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
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    rep(i,n) cin >> x[i];
    rep(i,m) cin >> y[i];
    sort(x.rbegin(), x.rend());
    sort(y.begin(), y.end());
    if (x[0] >= y[0]) {
        cout << "War" << endl;
        return 0;
    }
    for (int z = X+1; z <= Y; z++) {
        if (x[0] < z && y[0] >= z) {
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    return 0;
}