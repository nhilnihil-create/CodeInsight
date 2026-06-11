#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll sum = 0, s = 0;
    int ans = 0, cnt = 0;
    rep(i,n) cin >> a[i];
    vector<int> d;
    rep(i,n) { 
        cin >> b[i]; 
        if(a[i] > b[i])  { 
            d.push_back(a[i]-b[i]);
            s+=a[i]-b[i];
        }
        if(b[i] > a[i]) {
            sum+=b[i]-a[i];
            cnt++;
        }
    }
    if(s < sum) { cout << -1 << endl; return 0;}
    sort(all(d));
    reverse(all(d));
    ans = cnt;
    rep(i,d.size()) {
        if(sum<=0) break;
        sum-=d[i];
        ans++;
    }
    cout << ans << endl;

    return 0;
}
