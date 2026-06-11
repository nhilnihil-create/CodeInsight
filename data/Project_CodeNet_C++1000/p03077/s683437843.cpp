#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
    ll q = (n-1)/a;
    ll r = (n-1)/b;
    ll s = (n-1)/c;
    ll t = (n-1)/d;
    ll u = (n-1)/e;
    cout << max({q,r,s,t,u}) + 5 << endl;
}