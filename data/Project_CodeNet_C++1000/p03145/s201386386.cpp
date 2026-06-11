#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define in insert
#define ff first
#define ss second
#define e endl
#define MAXN 200005
#define debug cout<<"we are debuuging"<<endl;
#define MOD 998244353
ll fast_expo(ll x,ll p)
{if(p==0) return 1;
else if(p%2==0){ ll t=fast_expo(x,p/2)%MOD;return (t*t)%MOD;} else return (x*(fast_expo(x,p-1))%MOD)%MOD;}
int main()
{
     int a[3];
     cin>>a[0]>>a[1]>>a[2];
     sort(a,a+3);
     cout<<(a[0]*a[1])/2<<e;
}
