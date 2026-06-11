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
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    int tot = 0;
    rep(i,n-1) tot += l[i];
    if (l[n-1] < tot) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}