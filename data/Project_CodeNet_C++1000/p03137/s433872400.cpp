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
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m),d(m-1);
    rep(i,m) cin>>a[i];
    if(n>=m){
        cout<<0;
        return 0;
    }
    sort(all(a));
    int dis=0;
    rep(i,m-1){
        d[i]=abs(a[i+1]-a[i]);
        dis+=d[i];
    }
    sort(all(d));
    reverse(all(d));
    ll koma=1,i=0;
    while(koma<n&&dis-d[i]>0){
            dis-=d[i];
            koma++;
            i++;
    }
    cout<<dis;
}