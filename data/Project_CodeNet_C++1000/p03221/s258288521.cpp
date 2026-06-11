#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
    int n,m;cin >>n>>m;
    vector<int>p(m);
    vector<int>y(m);
    for (int i = 0; i < m; ++i) {
        cin >>p[i]>>y[i];
        p[i]--;
    }
    vector<vector<int>>val(n);//p[i]ごとのy[i]をまとめる
    for (int j = 0; j < m; ++j) {
        val[p[j]].push_back(y[j]);
    }
    for (int v = 0; v < n; ++v) {
        sort(all(val[v]));
       // val[v].erase(unique(all(val[v])),val[v].end());
        //今回は不要　ダブりをなくす
    }
    for (int i = 0; i < m; ++i) {
        int v=p[i];
        printf("%06d",v+1);
        int id=lower_bound(all(val[v]),y[i])-val[v].begin();
        printf("%06d\n",id+1);
    }
    return 0;
}