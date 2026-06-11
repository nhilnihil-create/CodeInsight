#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 2e5+50, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
int a[N] ;
int main()
{
    Tsetso
    int n , k;
    cin >> n >> k ;
    for ( int i = 0 ; i < n ; i++)
            cin >> a[i] ;
    int mn = 2e9 , s = 0;
    sort(a,a+n) ;
    for ( int i = k-1 ; i < n ; i++)
                mn = min(mn,a[i]-a[s++]);
    cout << mn ;
}
