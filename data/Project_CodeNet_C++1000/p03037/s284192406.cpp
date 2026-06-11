#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> l(m);
    vector<int> r(m);
    rep(i,m) cin >> l.at(i) >> r.at(i);
    int l_max = 0;
    int r_min = INF;
    rep(i,m) l_max = max(l_max,l.at(i));
    rep(i,m) r_min = min(r_min,r.at(i));
    int ans = max(0,r_min-l_max+1);
    cout << ans << endl;
}