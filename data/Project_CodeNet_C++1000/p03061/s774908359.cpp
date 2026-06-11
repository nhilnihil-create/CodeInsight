#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//ユークリッドの互除法
ll gcd(ll x,ll y){
    if(x > y) swap(x,y);
    if(x == 0) return y;
    return gcd(x,y%x);
};

int main(){
    int n;
    cin >> n;
    vector<int> f(n),b(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    f[0] = a[0];
    b[n-1] = a[n-1];
    for(int i = 1; i < n; i++){
        f[i] = gcd(f[i-1],a[i]);
        b[n-i-1] = gcd(b[n-i],a[n-i-1]);
    }
    ll ans = b[1];
    for(int i = 1; i < n; i++){
        ans = max(ans,gcd(f[i-1],b[i+1]));
    }
    cout << ans << endl;
    return 0;
}