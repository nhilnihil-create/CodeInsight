#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)
using ll = long long;
using Graph = vector<vector<int>>;
template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}
 
int N,M;
vector<vector<int>>G;
bool flag=true;
int co[100005];
int wh,bl;
void dfs(int x){
    if(co[x]==1)wh++;
    else bl++;
    for(int i:G[x]){
        if(co[i]&&co[i]==co[x]){
            flag=false;return;
        }
        if(co[i])continue;
        co[i]=co[x]*-1;
        dfs(i);
    }
}
signed main(){
    cin>>N>>M;G.resize(N);
    rep(i,M){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    co[0]=1;
    dfs(0);
    if(flag){
        //二部グラフでない場合
        cout << wh*bl-M << "\n";
        return 0;
    }else {
        //二部グラフの場合
        cout << N*(N-1)/2-M << "\n";
        return 0;
    }
}