// ABC107C
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int ans = 1001001001;
    rep(i, n-k+1) {
        int l = x[i], r = x[i+k-1];
        ans = min(ans, min(abs(l-r)+abs(l), abs(l-r)+abs(r)));
    }
    cout << ans << endl;
    return 0;
}