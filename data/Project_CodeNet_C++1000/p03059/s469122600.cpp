#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define pi acos(-1.0)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define pop pop_back
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
int main()
{
    boost;
    int x,b,t;
    cin>>x>>b>>t;
    if(b>t)
     cout<<0<<endl;
     else
     {
         cout<<b*(t/x)<<endl;
     }
     return 0;
}