#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> as(n);
    rep(i, n) cin >> as[i];
    int md = 1e9;
    rep(l, n-k+1) {
        int r = l+k-1; 
        int d =  abs(as[l]-as[r]);
        md = min(md, abs(as[l]) + d );
        md = min(md, abs(as[r]) + d );
    }
    cout << md << endl;
    return 0;
}