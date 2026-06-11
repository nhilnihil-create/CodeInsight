#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    int n,m;
    cin >> n >> m;
    vector<P> p(m);
    rep(i,m) cin >> p[i].first >> p[i].second;
    sort(p.begin(),p.end());
    int ans=m, l=p[0].first, r=p[0].second;
    for(int i=1; i<m; ++i){
        if(r<=p[i].first){
            l=p[i].first;
            r=p[i].second;
        }
        else{
            if(r>p[i].second){
                l=p[i].first;
                r=p[i].second;
                --ans;
            }else{
                l=p[i].first;
                --ans;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}