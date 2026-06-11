#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n,x;
    cin >> n >> x;
    vi a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(), a.end());
    int64_t res = 0;
    int64_t sum = 0;
    rep(i,n){
        x -= a.at(i);
        if(x<0) break;
        if(x>=0) res++;
    }
    if(x>0) res--;
    cout << res << endl;
}