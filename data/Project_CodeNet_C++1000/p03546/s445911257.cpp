#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;



int main()
{
    int h,w;
    cin>>h>>w;
    vector< vector<int>> c(10,vector<int>(10));
    vector< vector<int>> a(h,vector<int>(w));
    rep(i,10)
    {
        rep(j,10)
        {
            cin>>c[i][j];
        }
    }
    rep(i,h)
    {
        rep(j,w)
        {
            cin>>a[i][j];
        }
    }
        rep(k,10)rep(i,10)rep(j,10)if(c[i][j]>c[i][k]+c[k][j])c[i][j]=c[i][k]+c[k][j];

    ll ans=0;
    rep(i,h)
    {
        rep(j,w)
        {
            if(a[i][j]==-1)continue;
            if(a[i][j]!=1)
            {
                ans+=c[a[i][j]][1];
            }
        }
    }
    cout<<ans<<endl;

}
