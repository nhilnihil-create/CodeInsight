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
    ll m = n;
    if(n%2) --m;
    map<pair<ll,ll>, ll> muda;
    for(i = 1;i <= m/2;++i){
        muda[make_pair(i,m+1-i)] = 0;
    }
    ll ans = n*(n-1)/2 - muda.size();
    cout << ans << endl;
    for(i = 1;i <= n-1;++i){
        for(j = i+1;j <= n;++j){
            if(!muda.count(make_pair(i,j))){
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}