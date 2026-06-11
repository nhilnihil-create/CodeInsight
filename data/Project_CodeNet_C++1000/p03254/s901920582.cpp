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
    ll n,x,cnt=0; cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    rep(i,n){
        x-=a[i];
        if(x<0) break;
        if(i==n-1&&x>0) break;
        cnt++;
    }
    cout<<cnt;
}