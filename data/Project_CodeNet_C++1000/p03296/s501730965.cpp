#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int cnt = 1, ans = 0;
    for (int i = 1; i < n;++i){
        if(a[i-1]==a[i])
            ++cnt;
        else{
            ans += cnt / 2;
            cnt = 1;
        }
    }

    ans += cnt / 2;
    cout << ans << endl;

    return 0;
}