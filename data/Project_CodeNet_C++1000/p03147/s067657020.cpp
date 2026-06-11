#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int>h(n);
    rep(i, 0, n)cin >> h[i];
    int ans = h[0];
    rep(i, 0, n-1){
        if(h[i] < h[i+1])ans+=h[i+1]-h[i];
    }
    cout << ans << endl;
}