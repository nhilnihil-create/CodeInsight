#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    fast ;
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//#endif
    ll n,g,x;
    cin >> n ;
    cin >> x ;
    n--;
    while(n--)
    {
        cin >> g ;
        x=__gcd(x,g);
    }
    cout << x << "\n";
    return 0;
}
