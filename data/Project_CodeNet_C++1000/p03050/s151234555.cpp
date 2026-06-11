#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prll(a,sz)  cout<<a[0];for(ll i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<ll,ll>pi;
typedef pair<ll,ll>pll;
//ll fx[]={0,0,1,-1};
//ll fy[]={1,-1,0,0};
//ll gx[]={0,0,1,1,1,-1,-1,-1};
//ll gy[]={1,-1,0,1,-1,0,1,-1};
const ll N=100010;
ll n;
ll check(ll b)
{
    if(b-1==0)return 0;
    if(n%(b-1)==0)return 0;
    return b-1;
}
int main()
{
    IOS;
    cin>>n;
    ll res=0;
    ll sq=sqrt(n);
    for(ll i=1;i<=sq;i++)
    {

        ll b=(n/i)-1;
        if(b==0)continue;
        if(n%b==n/b)
        {
            res+=b;
//            cout<<"b = "<<b<<endl;
        }
    }
    cout<<res<<endl;
}






