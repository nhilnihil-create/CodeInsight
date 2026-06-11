#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)  cin >> a.at(i);
    
    vector<ll> sum(n+1, 0);
    map<ll, ll> obj;
    for(int i=0; i<n; i++) sum[i+1] = sum[i]+a[i];
    for(int i=0; i<=n; i++) obj[sum[i]] += 1;
    ll ans=0;
    for(auto x: obj){
        ans += x.second*(x.second-1)/2;
    }
    cout << ans << endl;
}