#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

vector<int> ra(MX,0);
vector<int> par(MX,0);


int find(int x) {
    if(par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(ra[x]<ra[y]) {
        par[x] = y;
    }else {
        par[y] = x;
        if(ra[x]==ra[y]) ra[x]++;
    }

}

bool same(int x, int y) {
    return find(x) == find(y);
}

signed main(){
    int n, m ;
    cin >> n >> m;

    vector<int> p(n,0);
    vector<vector<int>> xy(m, vector<int>(2)); 
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]-=1;
        par[i] = i;
    }

    for (size_t i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        unite(x-1,y-1);
    }

    int ans=0;
    for (size_t i = 0; i < n; i++)
    {
        if(same(p[i],i)) ans++;
    }

    cout << ans << endl;
    


    
    
}