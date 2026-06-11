#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int main() {
    ll n;cin >> n;
    ll a[n],b[n],c[n];
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> c[i];
    
    
    map<ll,ll>mp;
    rep(i,n)mp[b[i]]++;
    sort(a,a+n),
    sort(b,b+n);
    sort(c,c+n,greater<int>());
    
    ll alina = 0;
    for(auto p : mp){
        if(p.second < 1)continue;
        
        ll OK = n,NG = -1;
        while(abs(OK-NG) > 1){
            ll mid = (OK+NG)/2;
            if(a[mid] >= p.first)OK = mid;
            else NG = mid;
        }
        ll ok = n,ng = -1;
        while(abs(ok-ng) > 1){
            ll mid = (ok+ng)/2;
            if(c[mid] <= p.first)ok = mid;
            else ng = mid;
        }
        
        alina += ok*OK*p.second;
    }
    
    cout << alina << endl;
}