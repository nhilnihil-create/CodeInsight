#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 2e5+10, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
int a;
int main()
{
    Tsetso ;
    int n, k ;
    cin >> n >> k ;
    map < int, int > mp ;
    set < int > s ;
    for ( int i = 0 ; i < n ; i++)
    {
        cin >> a;
        s.insert(a);
        mp[a]++ ;
    }
    vector < int> v ;
    for (auto i : s )
        v.push_back(mp[i]);
    sort(v.begin(),v.end());
    if ( v.size() <= k)
            return cout << 0 , 0 ;
    int ans = 0;
    for ( int i = 0 ; i< v.size()-k ;i++)
            ans += v[i] ;
    cout << ans ;
}
