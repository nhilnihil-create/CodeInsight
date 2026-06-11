//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debugg cout<<"debugged\n";
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll n,t;

typedef struct node{
    ll xx,yy,hh;
}node;
void solve()
{
    cin>>n;
    vector<node> ar(n),ans;
    node nn;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i].xx>>ar[i].yy>>ar[i].hh;
        if(ar[i].hh>=1)
            nn=ar[i];
    }
    for(int x=0;x<=100;x++)
    {
        for(int y=0;y<=100;y++)
        {
            ll H=max(0ll,nn.hh+abs(nn.xx-x)+abs(nn.yy-y));
            bool flag=0;
            for(int i=0;i<n;i++)
            {
                if(max(0ll,H-abs(ar[i].xx-x)-abs(ar[i].yy-y))!=ar[i].hh)
                    {flag=1;break;}
            }
            if(!flag)
            {
                node aaa;
                aaa.xx=x;aaa.yy=y;aaa.hh=H;
                ans.pb(aaa);
            }
        }
    }
    if(ans.size()==1)
        cout<<ans[0].xx<<" "<<ans[0].yy<<" "<<ans[0].hh<<endl;
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}
