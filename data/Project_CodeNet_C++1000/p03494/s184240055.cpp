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
    ll n,flag=0,cnt=0; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    while(1){
        rep(i,n){
            if(a[i]%2!=0) flag++;
            a[i]=a[i]/2;
        }
        if(flag!=0) break;
        cnt++;
    }
    cout<<cnt;
}