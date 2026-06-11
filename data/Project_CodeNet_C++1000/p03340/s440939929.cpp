#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sum = 0; 
    ll ans = 0;
    int r = 0;
    for(int l = 0; l < n; ++l) {
        while(r < n && (sum + a[r]) == (sum ^ a[r])){
            sum+=a[r];
            r++;
        }
        ans += r-l;
        sum ^= a[l];
    }
    cout << ans << endl;
    return 0;
}