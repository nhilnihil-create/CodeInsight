#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
ll GCD(ll a,ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}
int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll ans;
    rep(i,n){
        cin>>a[i];
        if(i==0) ans=a[i];
        else ans=GCD(max(ans,a[i]),min(ans,a[i]));
    }
    cout<<ans;
}