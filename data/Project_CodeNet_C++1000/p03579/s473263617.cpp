#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

std::vector<int> bipartite(std::vector<std::pair<int,int>> edge){
    int E = edge.size();
    if(E==0)return {};
    int V = 0;
    for(int i=0;i<E;i++){
        V=std::max(V,edge[i].first+1);
        V=std::max(V,edge[i].second+1);
    }
    std::vector<int> R(V,-1);
    std::vector<int> S(0);
    std::vector<std::vector<int>> es(V,std::vector<int>(0));
    for(int i=0;i<E;i++){
        es[edge[i].first].push_back(edge[i].second);
        es[edge[i].second].push_back(edge[i].first);
    }
    std::queue<int> Q;
    std::vector<bool> visited(V,false);
    for(int j=0;j<V;j++){
        if(visited[j])continue;
        Q.push(j);
        R[j]=0;
        visited[j]=true;
        while(!Q.empty()){
            int q=Q.front();
            Q.pop();
            visited[q]=true;
            for(int i=0;i<es[q].size();i++){
                if(R[es[q][i]]==R[q]){
                    return S;
                }
                if(visited[es[q][i]])continue;
                Q.push(es[q][i]);
                R[es[q][i]]=1-R[q];
            }
        }
    }
    return R;
}

signed main(void){
    int N,M,a,b;
    vector<pair<int,int>> AB;
    cin >> N >> M;
    REP(i,M){
        cin >> a >> b;
        a--;b--;
        AB.push_back({a,b});
    }
    vector<int> E = bipartite(AB);
    int x=0,y=0;
    REP(i,E.size()){
        if(E[i]==0){
            x++;
        }else{
            y++;
        }
    }
    if(x==0 || y==0){
        cout << N*(N-1)/2 - M << endl;
    }else{
        cout << x*y - M << endl;
    }
    return 0;
}

