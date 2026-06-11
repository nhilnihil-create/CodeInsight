#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct UnionFind{
    vector<int> d;
    UnionFind(int n): d(n,-1) {}
    int find(int x){
        if(d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(d[x] < d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return -d[find(x)];
    }
};

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    UnionFind uf(n);
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        uf.unite(x,y);
    }

    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++) {
        int pr=uf.find(i);
        mp[pr].emplace_back(i);
        mp[pr].emplace_back(p[i]);
    }

    int ans=0;
    for(auto itr=mp.begin() ; itr!=mp.end() ; itr++) {
        int k=itr->first;
        sort(mp[k].begin(),mp[k].end());
        int s=mp[k].size();
        int cnt=0;
        for(int i = 1; i < s; i++) {
            if(mp[k][i-1]==mp[k][i]) cnt++;
        }
        ans+=cnt;
    }
    cout << ans << "\n";

    return 0;
}