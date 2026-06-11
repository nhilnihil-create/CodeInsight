#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int MAX_V=210;

vvin g(MAX_V);//グラフの隣接リスト表現
vin match(MAX_V);//マッチングのペア
vbo used(MAX_V);

void add_edge(int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

//増加パスをdfsで探す
bool dfs(int v){
    used[v]=true;
    for(auto u:g[v]){
        int w=match[u];
        if(w<0||(!used[w]&&dfs(w))){
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}

//二部グラフの最大マッチングを求める
int max_matching(int v){//vは頂点数
    int res=0;
    fill(all(match),-1);
    rep(i,v){
        if(match[i]<0){
            fill(all(used),false);
            if(dfs(i))res++;
        }
    }
    return res;
}

int main(){
    int n;cin>>n;
    vin a(n),b(n),c(n),d(n);
    rep(i,n)cin>>a[i]>>b[i];
    rep(i,n)cin>>c[i]>>d[i];
    rep(i,n)rep(j,n){
        if(a[i]<c[j]&&b[i]<d[j])add_edge(i,j+n);
    }
    cout<<max_matching(2*n)<<endl;
}