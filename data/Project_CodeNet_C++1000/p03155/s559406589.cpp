#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD=1e9 + 7 ;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX =  3e5 ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m  , k , Q , l , x , y, ans; string s;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   // freopen("test.in","r",stdin);
    ll h , w;
    cin>>n>>h>>w;
    if( h > n || w > n)
        return cout<<0 , 0;
    cout<<(n - h + 1)*(n - w + 1);


    return 0;
}
