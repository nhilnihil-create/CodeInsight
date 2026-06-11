#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<pair<int,int>> v[100010];
int main(){
    cout << fixed << setprecision(10);
    int n,m;
    cin >> n >> m;
    vector<int> p(m,0), y(m,0);
    rep(i,m) cin >> p[i] >> y[i];
    rep(i,m){
        v[p[i]].push_back(make_pair(y[i],i));
    }
    vector<pair<int,int>> ans(m); 
    for(int i=0; i < 100010; i++){
        sort(v[i].begin(),v[i].end());
        for(int j=0;j < v[i].size(); j++){
            ans[v[i][j].second] = make_pair(i, j+1);
        }
    }
    rep(i,m){
        cout << setw(6) << setfill('0') << ans[i].first << setw(6) << setfill('0') << ans[i].second  << setprecision(6) << endl;
    }
    return 0;
}