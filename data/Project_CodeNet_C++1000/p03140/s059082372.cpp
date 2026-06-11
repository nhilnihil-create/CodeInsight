#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    int n; cin >> n;
    string a, b, c; cin >> a >> b >> c;
    int ans = 0;
    rep(i, 0, n){
        if(a[i] == b[i] && b[i] == c[i]) continue;
        else if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) ans += 2;
        else ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
