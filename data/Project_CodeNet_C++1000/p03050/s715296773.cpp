#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    ll ans = 0;
    for(i = 1;i <= sqrt(n)+1;++i){
        if(n%i) continue;  
        j = n/i;
        ll m = j-1;
        if(i >= m) continue;
        else ans += m;
    }
    cout << ans << endl;
    return 0;
}