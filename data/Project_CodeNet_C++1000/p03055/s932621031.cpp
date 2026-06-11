#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
int MAX_V = 200100;
vector <vector<pair <int,int>>> g(MAX_V,vector <pair <int,int>>());
pair <int,int> treedfs(int now, vector <bool> &v, int cost=0 ){
    
    if(v[now]) return {-1, -1};
    else v[now] = true;
    pair <int,int> ret = {cost, now};
    for(int i=0;i<g[now].size();i++){
        ret = max(ret, treedfs( g[now][i].F,v,cost + g[now][i].S));
    }
    return ret;
}
int Tree_diameter(){
    vector <bool>  v(MAX_V) ;
    pair <int,int> step1 = treedfs(0,v,0);
    vector <bool>  v2(MAX_V) ;
    pair <int,int> step2 = treedfs(step1.S,v2,0);
   return step2.F;
}
signed main(void){
    int n; cin>>n;
    rep(i,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].push_back({b,1});
        g[b].push_back({a,1});
    }
    int x = Tree_diameter();
    if(x%3 == 1) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}
