#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define ff first
#define sc second
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    //freopen("test.txt","r",stdin);
    ll n,ind=0,i,j,ans=0,ev=0,od=0;
    cin>>n;
    vector<ll>v(n);
    for(auto &ii:v)cin>>ii;
    ll l[n+2];
    ll r[n+2];
    l[0]=r[n+1]=0;
    for(i=1;i<=n;i++)
    {
        l[i]=__gcd(l[i-1],v[i-1]);
    }
    for(i=n-1;i>=0;i--)
    {
        r[i+1]=__gcd(r[i+2],v[i]);
    }
    ans=1;
    for(i=1;i<=n;i++)
    {
        ans=max(__gcd(l[i-1],r[i+1]),ans);
    }
    cout<<ans<<endl;
    return 0;
}

