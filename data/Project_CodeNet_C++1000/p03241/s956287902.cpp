#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int ans = 1;
    repp(i,sqrt(m)+1,1){
        if (m % i != 0) continue;
        if (m/i >= n) ans = max(ans,i);
        if (i >= n) ans = max(ans,m/i);
    }
    cout << ans << endl;
}