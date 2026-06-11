#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    ll n,k; cin >> n >> k;
    ll ans = 0;
    for(ll i = k+1; i <= n; i++){
        ans += (n/i)*(i-k);
        ans += max(0LL, (n%i)-k+1);
    }
    if(k == 0) ans = n*n;
    cout << ans << endl;
}