#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define MAXN   1000005
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
int main()
{
    string x , y ;
    cin >> x >> y;
    string z = y ;
    reverse(y.begin(),y.end());
    if ( y != x)
            return cout << "NO" , 0;
    reverse(x.begin(),x.end());
    if ( x != z)
            return cout << "NO" , 0;
    cout << "YES" ;
}
