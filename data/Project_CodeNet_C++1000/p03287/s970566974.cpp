#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 2e5+50, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
ll a[N];
int main()
{
    Tsetso
    map < int , int > mp ;
    int n , m ;
    cin >> n >> m ;
    ll ans = 0 ;
    mp[0] = 1 ;
    for ( int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
        a[i] += a[i-1];
        a[i] %= m ;
        ans += mp[a[i]] ;
        mp[a[i]]++ ;
    }
    cout << ans ;
}
