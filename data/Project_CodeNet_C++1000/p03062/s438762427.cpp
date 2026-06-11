#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    ll ans = 0;
    int count = 0;
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] < 0){
            a[i]*=(-1);
            count ++;
        }
        ans += a[i];
    }
    if(count%2 == 0)cout << ans << endl;
    else{
        sort(a.begin(), a.end());
        cout << ans-2*(a[0]) << endl;
    } 
}