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
    rep(i,n) {
        int lower = i;
        int upper = lower+k-1;
        if(upper >= n || lower < 0) continue;
        chmin(d_min, abs(x[lower])+abs(x[upper]-x[lower]));
        chmin(d_min, abs(x[upper])+abs(x[upper]-x[lower]));
    }
    cout << d_min << endl;
}