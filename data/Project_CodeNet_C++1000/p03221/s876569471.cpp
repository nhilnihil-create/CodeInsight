#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 500000000
#define IOS ios_base::sync_with_stdio(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
bool check(int n,int p){return (1<<p)&n;}
vector<int>v[100010];
pi ara[100010];
int main()
{
    IOS;
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        v[a].pb(b);
        ara[i]={a,b};
    }
    for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
    for(int i=0;i<m;i++)
    {
        int a=ara[i].ff;
        int pos=upper_bound(v[a].begin(),v[a].end(),ara[i].ss)-v[a].begin();
//        cout<<a<<" "<<pos<<endl;
        printf("%06d%06d\n",a,pos);
    }
}
