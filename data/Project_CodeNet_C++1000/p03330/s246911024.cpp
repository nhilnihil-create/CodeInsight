#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define all(v) v.begin() , v.end()
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int mod = 998244353;

int32_t main()
{   fastio;

    int n , c;
    cin>>n>>c;

    int d[c+1][c+1];

    for(int i=1; i <= c; i++)
    {
        for(int j=1; j <= c; j++)
        {
            cin>>d[i][j];
        }
    }
    map<int , vector<int>>mp;

    int arr[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) {
            cin>>arr[i][j];
            mp[(i+j)%3].pb(arr[i][j]);
        }
    }

    int ans=1e13;
    vector<pii>a;
    vector<pii>b;
    vector<pii>l;
    for(int i=1; i <= c; i++)
    {
        int sum=0;
        for(auto x:mp[0])
        {
            sum += d[x][i];
        }
        a.pb({sum , i});
    }
    for(int i=1; i <= c; i++)
    {
        int sum=0;
        for(auto x:mp[1])
        {
            sum += d[x][i];
        }
        b.pb({sum , i});
    }
    for(int i=1; i <= c; i++)
    {
        int sum=0;
        for(auto x:mp[2])
        {
            sum += d[x][i];
        }
        l.pb({sum , i});
    }
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            for(int k=0; k<l.size(); k++) {
                if(l[k].S != b[j].S && b[j].S != a[i].S && a[i].S != l[k].S)
                {
                    ans=min(ans , l[k].F+a[i].F+b[j].F);
                }
            }
        }
    }
    cout<<ans<<"\n";

}
