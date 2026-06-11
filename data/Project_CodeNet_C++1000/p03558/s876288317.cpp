#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

template < typename T >
void vprint(T &V){
	for(auto v : V){
        cout << v << " ";
    }
	cout << endl;
}

struct Edge{
    ll to;
    ll cost;
    Edge(ll to, ll cost): to(to), cost(cost) {}
};

vector<vector<Edge> > graph;

void printGraph(){
    FOR(i, 0, graph.size()){
        for(auto e : graph[i]){
            cout << i << "->" << e.to << " " << e.cost << endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    int K;
    cin >> K;

    graph.resize(K);
    // グラフデータ
    // graph[0].push_back(Edge(1, 1));
    // graph[1].push_back(Edge(2, 1));
    // graph[1].push_back(Edge(4, 0));
    // graph[2].push_back(Edge(3, 1));
    // graph[3].push_back(Edge(4, 1));
    // graph[3].push_back(Edge(0, 0));
    // graph[4].push_back(Edge(5, 1));
    // graph[5].push_back(Edge(0, 1));
    // graph[5].push_back(Edge(2, 0));
    
    // +1の分
    FOR(i, 0, K-1){
        graph[i].push_back(Edge(i+1, 1));
    }
    graph[K-1].push_back(Edge(0, 1));

    // +0の分
    FOR(i, 1, K){
        ll to = (10*i)%K;
        ll cost = 0;
        if(i!=to){
            graph[i].push_back(Edge(to, cost));        
        }
    }

    // 確認
    //printGraph();

    vector<ll> d(K);
    fill(ALL(d), inf);

    deque<ll> que;
    // 1からスタート
    d[1] = 0;
    que.push_front(1);

    while(!que.empty()){
        
        // 先頭の取り出し
        auto first = que.front(); 
        que.pop_front();

        // p("");
        // pn(first);

        auto lst = graph[first];
        for(Edge e : lst){
            ll dist = d[first] + e.cost;
            if(dist < d[e.to]){
                d[e.to] = dist;
                if(e.cost==0){
                    que.push_front(e.to);
                }else{
                    que.push_back(e.to);
                }                
            }
        }
    }

    p(d[0]+1);
    
    return 0;
}