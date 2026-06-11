#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<int>a(n), b(n), c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<ll>sum(n, 0);
    for(int i=0;i<n;i++){
        auto it = upper_bound(c.begin(), c.end(), b[i]);
        sum[i] = c.end()-it;
    }
    for(int i=n-2;i>=0;i--) sum[i] += sum[i+1];

    ll ans = 0;
    for(int i=0;i<n;i++){
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        ans += sum[it-b.begin()];
    }

    cout << ans << endl;

}