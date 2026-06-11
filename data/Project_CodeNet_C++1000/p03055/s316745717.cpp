#include <iostream>
#include <vector>

using namespace std;
template<class T> inline bool chmax(T &a, T b){ if(a < b){a = b; return true;} return false;}

struct Edge{
    int from,to,weight;
    Edge(int f,int t,int w) : from(f), to(t), weight(w){}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

class Tree{
    public:
        Tree(int size) : mGraph(size) {}
        void add_edge(int s, int t, int w = 1){
            mGraph[s].emplace_back(s,t,w);
            mGraph[t].emplace_back(t,s,w);
        }

        // diameter of a tree
        pair<int,int> dfs(int v, int pv){
            pair<int,int> ret(0,v);
            for(Edge nv : mGraph[v]){
                if(nv.to == pv) continue;
                pair<int,int> tmp = dfs(nv.to,v);
                if(chmax(ret.first,tmp.first + nv.weight)){
                    ret.second = tmp.second;
                }
            }
            return ret;
        }

        int diameter(){
            pair<int,int> s = dfs(0,-1);
            pair<int,int> t = dfs(s.second,-1);
            return t.first;
        }
        //
    private:
        Graph mGraph;
};

int main(){
    int n,s,t,w;
    cin >> n;
    Tree tree(n);
    for(int i = 0; i < n-1; ++i){
        cin >> s >> t;
        --s;--t;
        tree.add_edge(s,t);
    }
    cout << (tree.diameter() % 3 != 1 ? "First" : "Second") << '\n';
    return 0;
}