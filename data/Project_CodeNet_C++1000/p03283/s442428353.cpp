#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,q;cin >> n >> m >> q;
    vector<vector<int>> c(n+1,vector<int>(n+1));
    rep(i,m){
        int l,r;cin >> l >> r;
        c[l][r]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j]+=c[i][j-1];
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            c[i][j]+=c[i-1][j];
        }
    }
    rep(i,q){
        int s,t;cin >> s >> t;
        cout << c[t][t]-c[t][s-1]-c[s-1][t]+c[s-1][s-1] << endl;
    }
}