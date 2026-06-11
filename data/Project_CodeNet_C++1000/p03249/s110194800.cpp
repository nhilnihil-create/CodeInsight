#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define PI acos(-1.0)
const int N=1e5 + 5;
const int M=1e5 + 5;
 
ll d[N],sub[N];
vector <int> g[N]; 
vector < pair < ll , int > > v;
bool vis[N];
ll ans[N],bar[N];
int n;

void dfs(int s)
{
    vis[s]=true;
    for(int i=0;i<g[s].size();i++){
        int x = g[s][i];
        if(!vis[x]){
            dfs(x);
        bar[s]+=bar[x]+sub[x];
        }
    }
}

void dfs1(int s)
{
    vis[s]=true;
    for(int i=0;i<g[s].size();i++){
        int x = g[s][i];
        if(!vis[x]){
            ll ff = ans[s];
            ff -= bar[x]+sub[x];
            ff += n-sub[x]+bar[x];
            ans[x]=ff;
            dfs1(x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i;
    map <ll,int> mp;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>d[i];
        mp[d[i]]=i;
        v.pb(mkp(d[i],i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(i=1;i<=n;i++){
        sub[i]=1;
    }

    for(i=0;i<n-1;i++){
        int x = v[i].se;
        ll foo = d[x]-((ll)n - 2*sub[x]);
        int y = mp[foo];

        if(y==0){
        //    cout << i << endl;
            cout << -1 << endl;
            return 0;
        }
        sub[y]+=sub[x];

        g[y].pb(x);
        g[x].pb(y);
    }
    int yy = v[n-1].se;
    for(i=1;i<=n;i++){
        vis[i]=false;
    }
    for(i=1;i<=n;i++){
        bar[i]=0;
    }
    dfs(yy);
    for(i=1;i<=n;i++){
        vis[i]=false;
    }
    ans[yy]=bar[yy];
    dfs1(yy);
    //cout << ans[1]<<endl;
    for(i=1;i<=n;i++){
        if(ans[i]!=d[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    for(i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            int x = g[i][j];
            if(x>i) cout << i << " " << x << endl;
        }
    }


 
    return 0;
}