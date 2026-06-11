#include <bits/stdc++.h>
using namespace std;
# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;

vector<int> edges[100001], from[100001];

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> dist(N, 0), par(N, 0), indeg(N, 0);

    REP(i, N - 1 + M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        indeg[b]++;
        edges[a].push_back(b);
        from[b].push_back(a);
    }

    int root = -1;
    REP(i, N) if(indeg[i] == 0) root = i;
    par[root] = -1;
    dist[root] = 0;

    // トポロジカルに処理
    // 入次数が０になったものから処理
    // DAGの最長経路問題
    queue<int> que;
    que.push(root);
    while(que.size()){
        int i = que.front();
        que.pop();
        for(int j : from[i]){
            if(dist[j] + 1 > dist[i]){
                par[i] = j;
                dist[i] = dist[j] + 1;
            }
        }
        // 対象からの辺を削り、入次数が0になったものが次の処理対象
        for(int j : edges[i]){
            indeg[j]--;
            if(indeg[j] == 0) que.push(j);
        }    
    }
    REP(i, N) cout << par[i] + 1 << endl;
    return 0;
}
