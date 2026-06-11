#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    
    int c = 0, d = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] <= a) c++;
        if (p[i] >= a + 1 && p[i] <= b) d++;
        if (p[i] >= b + 1) e++;
    }
    
    int ans;
    ans = min(c, min(d, e));
    cout << ans << endl;
    return 0;
}