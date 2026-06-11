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
const int N=100010;
pi pos[N];
int pre[N];
int main()
{
    IOS;
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int a;cin>>a;
            pos[a]={i,j};
        }
    }
    int mx=n*m;
    for(int i=1;i<=k;i++)
    {
        int d=0;
        for(int j=i+k;j<=mx;j+=k)
            {
                d+=abs(pos[j].ff-pos[j-k].ff)+abs(pos[j].ss-pos[j-k].ss);
                pre[j]=d;
//                cout<<"distance of "<<j<<" = "<<d<<endl;
            }
    }
    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<pre[r]-pre[l]<<endl;
    }
}






