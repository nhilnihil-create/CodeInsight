#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
vector<bool> used(100,false);

void dfs(int now, int u, int v, vector<vector<int> > &G){
    used[now]=true;
    for(auto to:G[now]){
        if(!used[to] && !((u==now && v==to) || (u==to && v==now))) dfs(to,u,v,G);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m),b(m);
    vector<vector<int> > G(n);
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]); G[b[i]].push_back(a[i]);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        int u=a[i];
        int v=b[i];
        for(int x=0;x<n;x++) used[x]=false;

        dfs(0,u,v,G);

        bool f=true;
        for(int x=0;x<n;x++) if(!used[x]) f=false;
        if(!f) ans++;
        //cout<<ans<<" ";
    }
    cout<<ans<<endl;
}