#include<bits/stdc++.h>
#define lld         long long int
#define llf         long double
#define pb          push_back
#define mp          make_pair
#define IN          insert
#define loopN(n)    for(lld i=0;i<n;i++)
#define loop(p,n)   for(lld i=p;i<=n;i++)
#define rloop(p,n)  for(lld i=n;i>=p;i--)
#define loop2(p,n)  for(lld j=p;j<=n;j++)
#define all(v)      v.begin(),v.end()
#define F1          first
#define F2          second
#define INF         2e18
#define FILE        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define PI          2*acos(0.0)
#define ISO         ios::sync_with_stdio(false);cin.tie(0)
#define mod         100000007
#define mem(a,b)    memset(a,b,sizeof(a))
using namespace std;

bool pal(lld n)
{
    vector<lld>a;
    while(n!=0)
    {
        a.pb(n%10);
        n/=10;
    }
    lld p=0,q=a.size()-1;
    while(p<=q)
    {
        if(a[p]!=a[q])return 0;
        p++;
        q--;
    }
    return 1;



}


int main()
{
    ISO;
    lld a,b;
    cin>>a>>b;
    lld ans=0;
    loop(a,b)
    {
        if(pal(i))ans++;
    }
    cout<<ans<<endl;








    return 0;
}

