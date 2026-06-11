#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    rep(i,n) {
        x-=a[i];
        if(x<0) break;
        ans++;

    }
    if(x>0) ans--;
    cout << ans << endl;
    return 0;
}