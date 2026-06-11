#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    if(m == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<P> a(m);
    rep(i, m)cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int l = a[0].first;
    int r = a[0].second;
    int ans = 0;
    for(int i = 1; i < m; i++){
        if(a[i].first >= r){
            ans++;
            l = a[i].first;
            r = a[i].second;
        }
        r = min(r, a[i].second);
        if(i == m - 1)ans++;
    }
    cout << ans << endl;
}