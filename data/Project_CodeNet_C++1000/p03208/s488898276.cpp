#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int k,n;
    cin>>n>>k;
    vector<ll> h(n);
    rep(i,n) cin>>h[i];
    sort(all(h));
    reverse(all(h));
    ll ans=h[0]-h[k-1];
    repi(i,1,n-k+1) ans=min(ans,h[i]-h[i+k-1]);
    cout<<ans;
}