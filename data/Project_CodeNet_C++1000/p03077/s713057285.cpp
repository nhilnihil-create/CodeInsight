#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
ll mod = 1e9+7;


int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
    ll ans = ceil(n*1.0 / min(e,min(d,min(c,min(a,b))))) + 4;
    cout << ans << endl;
}