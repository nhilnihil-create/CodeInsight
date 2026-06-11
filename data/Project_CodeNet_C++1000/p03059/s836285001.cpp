/*  TAHMID RAHMAN
    DAMIAN FOREVER
     MATH LOVER
    NEVER GIVE UP
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define GCD(a,b) __gcd(a,b);
#define endl "\n"
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define INFLL 9223372036854775807
#define debug 0
#define MAXN   100001
//Don't hesitate to ask me if you don't understand my code.......Happy coding,Tahmid...;
int main()
{
    fastio;
    ll a,b,t;
    cin>>a>>b>>t;
    if(t<a)
    {
        cout<<"0"<<endl;
    }
    else
    {
        ll x=t/a;
        cout<<x*b<<endl;
    }
}
