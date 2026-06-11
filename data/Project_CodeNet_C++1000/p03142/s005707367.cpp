#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n-1+m),b(n-1+m);
    rep(i,n-1+m) {
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
    }
    
    vector<vector<int>> graph(n);
    vector<int> deg(n,0);
    rep(i,n-1+m){
        graph[b[i]].push_back(a[i]);
        deg[a[i]]++;
    }
    
    queue<int> q;
    rep(i,n) if(deg[i]==0) q.push(i);
    
    vector<int> vec(n); //vec[i] -> 頂点iのsort後のindex
    int cnt=n-1;
    while(!q.empty()){
        int v=q.front(); q.pop();
        vec[v]=cnt; cnt--;
        
        for(auto nv:graph[v]){
            deg[nv]--;
            if(deg[nv]==0) q.push(nv);
        }
        
    }
    
    rep(i,n){
        int ans=-1;
        int MAX=-1;
        for(int x:graph[i]){
            if(vec[x]>MAX){
                MAX=vec[x];
                ans=x;
            }
        }
        cout<<ans+1<<endl;
    }
}
