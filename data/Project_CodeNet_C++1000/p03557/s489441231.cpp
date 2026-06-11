#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    rep(i,n) cin >> b[i];
    sort(all(b));
    rep(i,n) cin >> c[i];
    sort(all(c));
    
    ll sum=0;
    rep(i,n){
        auto x=lower_bound(all(a),b[i]);
        ll pos1 = distance(a.begin(),x);
        auto y=upper_bound(all(c),b[i]);
        ll pos2 = distance(c.begin(),y);
        sum+=pos1*(n-pos2);
    // cout << pos1 << ' ' << n-pos2 << ' ' << sum << endl;
    }
    cout << sum << endl;

    return 0;
}