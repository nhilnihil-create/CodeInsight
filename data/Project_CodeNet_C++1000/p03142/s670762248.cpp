#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;


ll N;ll M;


vector<vector<ll>> graph(100005, vector<ll>(0));  // DAG
vector<ll> order(0);  // トポロジカルソートされた頂点を格納
vector<bool> used(100005,0);  // 訪問済みフラグ

// 辿れるところまで辿る深さ優先探索
void dfs(ll u){
    if(used[u]) return;
    used[u] = true;
    for(ll v : graph[u]) dfs(v);
    order.emplace_back(u);     // 帰りがけ順で頂点を入れていく
}

// トポロジカルソート
//Nは頂点数
void tsort(ll N){
    for(ll v = 1; v <= N; v++) dfs(v);
    reverse(order.begin(), order.end());
}


int main(){
    cin >> N;
    cin >> M;
    vector<vector<ll>> parent(N+1, vector<ll>(0));
    for(ll i=0;i<N+M-1;i++){
        ll A,B;
        cin>>A>>B;
        graph[A].emplace_back(B);
        parent[B].emplace_back(A);
    ;}
    tsort(N);
    vector<ll> ans(N+1,0);
    vector<ll> where(N+1,0);
    for(ll i=1;i<=N;i++){
        where[order[i-1]]=i-1
    ;}
    for(ll i=1;i<=N;i++){
        ll Min=-INF;
        for(auto p: parent[i]){
            Min=max(where[p]-where[i],Min)
        ;}
        if(Min!=-INF){
            for(auto p: parent[i]){
                if(where[p]-where[i]==Min){
                    ans[i]=p;break;
                }
            ;}
        }
        
    ;}
   
    

    for(ll i=1;i<=N;i++){
        cout<<ans[i]<<endl;
    ;}


    return 0;
}
