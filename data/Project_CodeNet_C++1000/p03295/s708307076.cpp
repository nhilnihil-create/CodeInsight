#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<P> ab(m);
    rep(i,m)
    {
        cin>>ab[i].first>>ab[i].second;
        ab[i].first--;
        ab[i].second--;
    }
    sort(ab.begin(),ab.end());
    P prev=ab[0];
    int ans=1;
    for(int i=1;i<m;i++)
    {
        //cout<<ab[i].first<<" "<<ab[i].second<<endl;
        if(prev.second<=ab[i].first)
        {
            ans++;
            prev=ab[i];
        }
        else
        {
            prev.first=ab[i].first;
            prev.second=min(prev.second,ab[i].second);
        }
        
    }
    cout<<ans;

}
