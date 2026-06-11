#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
vector<int> G[100001];
bool visited[100001];
int ans=0;
//グラフの連結判定
int cnt=0;
void dfs(int now){//訪れたところに印を付けながら進んでいくイメージ
    visited[now] = true;
    for(int i=0;i<G[now].size();i++){
        //iが訪れておらず、nowとiがつながっていれば探索する
        int child = G[now][i];
        if(!visited[child]){
            dfs(child);
        }
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> x(m),y(m),z(m);
    rep(i,m){
        cin>>x[i]>>y[i]>>z[i];
        x[i]--,y[i]--;
        //connect[x[i]][y[i]]=
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }
    rep(i,n){
        visited[i]=false;
    }
    rep(i,n){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}