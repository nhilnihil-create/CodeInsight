#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    ll n;
    cin >> n;
    vector<ll> a(5);
    rep(i,5) cin >> a[i];
    ll mi = 1e16;
    rep(i,5) mi = min(mi,a[i]);
    ll ans;
    ans = n/mi+4;
    if(n%mi!=0) ans++;
    cans;
    return 0;
}