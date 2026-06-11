#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(m), y(m);
    vector<vector<int>> pref(n);
    rep(i,m){
        cin >> p[i] >> y[i];
        --p[i];
        pref[p[i]].push_back(y[i]);
    }
    rep(i,n) sort(ALL(pref[i]));
    rep(i,m){
        int v = p[i];
        printf("%06d", v+1);
        int id = lower_bound(ALL(pref[v]),y[i]) - pref[v].begin();
        printf("%06d\n", id+1); 
    }
    return 0;
}