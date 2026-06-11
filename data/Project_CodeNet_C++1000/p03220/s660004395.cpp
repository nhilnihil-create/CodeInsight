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
    double t, a;
    cin >> t >> a;
    vector<double> h(n);
    rep(i,n) cin >> h[i];
    rep(i,n) {
        h[i] = t - h[i]*0.006;
        h[i] = abs(a-h[i]);
    }
    int mn = 0;
    rep(i,n) {
        if (h[mn] > h[i]) mn = i;
    }
    cout << mn+1 << endl;
    return 0;
}