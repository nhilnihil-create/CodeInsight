#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fr first
#define sc second
#define N 300009
#define inf 2e16
#define pi pair<ll,ll>
#define pb push_back
using namespace std;
typedef long long ll;
ll a[509][509];
ll w,h;
struct info {
    ll a,b,c,d;
};
vector< info >ans;
int main()
{
    cin>>h>>w;
    for(ll i=1;i<=h;i++) for(ll j=1;j<=w;j++) cin>>a[i][j];
    for(ll i=1;i<=h;i++)
    {
        if(i%2==1)
        {
            for(ll j=1;j<=w;j++)
            {
                if(a[i][j]%2==1)
                {
                    info in;
                    in.a=i,in.b=j;
                    a[i][j]--;
                    if(j<w)
                    {
                        a[i][j+1]++;
                        in.c=i,in.d=j+1;
                        ans.push_back(in);
                    }
                    else 
                    {
                        if(i+1>h) continue;
                        a[i+1][j]++;
                        in.c=i+1,in.d=j;
                        ans.push_back(in);
                    }
                }
            }   
        }
        else
        {
            for(ll j=w;j>=1;j--)
            {
                if(a[i][j]%2==1)
                {
                    info in;
                    in.a=i,in.b=j;
                    a[i][j]--;
                    if(j>1)
                    {
                        a[i][j-1]++;
                        in.c=i,in.d=j-1;
                        ans.push_back(in);
                    }
                    else 
                    {
                        if(i+1>h) continue;
                        a[i+1][j]++;
                        in.c=i+1,in.d=j;
                        ans.push_back(in);
                    }
                }
            }
        }
    }
    ll sz=ans.size();
    cout<<sz<<endl;
    for(int i=0;i<sz;i++)
    {
        cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<" "<<ans[i].d<<endl;
    }
    return 0;
}
