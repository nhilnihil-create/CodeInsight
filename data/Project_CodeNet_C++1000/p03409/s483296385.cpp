#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+1;

int main()
{
    int n;
    cin>>n;
    vector<P> red(n);
    vector<P> blue(n);
    vector<bool> select(n,false);
    rep(i,n)
    {
        cin>>red[i].first>>red[i].second;
    }
    rep(i,n)
    {
        cin>>blue[i].first>>blue[i].second;
    }
    sort(blue.begin(),blue.end());
    sort(red.begin(),red.end());

    int ans=0;
    rep(i,n)
    {
        int greed=-1;
        int ymax=0;
        rep(j,n)
        {
            if(blue[i].first>red[j].first)
            {
                if(blue[i].second>red[j].second && ymax<=red[j].second && !select[j])
                {
                    ymax=red[j].second;
                    greed=j;
                }
            }

        }
        if(greed!=-1)
        {
            select[greed]=true;
            //cout<<i<<" "<<greed<<endl;
            //cout<<i<<" "<<greed<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
}