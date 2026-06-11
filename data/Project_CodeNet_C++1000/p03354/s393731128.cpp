#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

/*
struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};*/

vector<int> found(100005,false);
Graf g(100005);
queue<int> q,r;

void dfs(int s){
    if(found[s]){
        return;
    }else{
        found[s]=true;
        q.push(s);
        for(int i=0;i<g[s].size();++i){
            dfs(g[s][i]);
        }
        return;
    }
}

int main()
{
    int n;int m;
    cin >> n >> m;
    
    vector<int> p(n+1),x(m),y(m);
    vector<bool> flag(n+1,true);
    vector<bool> flag_(n+1,true);
    int size=0;
    
    rep(i,n)cin >> p[i+1];
    rep(i,m)cin >> x[i] >> y[i];

    rep(i,m){
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }
    FOR(i,n+1,1){
        if(!found[i]){
            dfs(i);
            
            while(!q.empty()){
                int a=q.front();
                
                if(flag[a]==true){
                    //cout << a << endl;
                    flag[a]=false;
                    r.push(a);
                }
                q.pop();
            }
            int b=r.size();
            rep(i,b){
                int a=r.front();
                r.pop();
                q.push(p[a]);
                r.push(a);
            }
            while(!q.empty()){
                int a=q.front();
                q.pop();
                if(flag[a]==true){
                    flag_[a]=false;
                }else if(flag_[a]==true){
                    flag[a]=true;
                }
            }
            while(!r.empty()){
                int a=r.front();
                r.pop();
                if(flag[a]==false){
                    flag_[a]=false;
                }
            }
        }

    }
    FOR(i,n+1,1){
        //cout << flag_[i] << endl;
        if(flag_[i]==true){
            size++;
        }
    }
    cout << size << endl;

    
}