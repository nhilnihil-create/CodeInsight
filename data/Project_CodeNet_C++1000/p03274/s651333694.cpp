#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int d_min = INT32_MAX;
    auto l_itr = lower_bound(x.begin(), x.end(), 0);
    int l;
    if(l_itr == x.end()) {
        cout << -x[n-k] << endl; return 0;
    }
    else {l = l_itr - x.begin();}
    if(l+k-1 <= n-1) chmin(d_min, x[l+k-1]);
    if (l-k+1 >= 0 && x[l] == 0) chmin(d_min, -x[l-k+1]);
    if (l-k >= 0 && x[l] != 0) chmin(d_min, -x[l-k]);
    rep(i,n) {
        int upper = i;
        int lower = upper-k+1;
        if(upper >= n || lower < 0) continue;
        if(upper < l || lower >= l) continue;
        chmin(d_min, 2*x[upper]-x[lower]);
        chmin(d_min, x[upper]-2*x[lower]);
    }
    cout << d_min << endl;
}