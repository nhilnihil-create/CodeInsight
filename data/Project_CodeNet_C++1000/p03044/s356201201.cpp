#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#include <list>
#include <cassert>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

struct Edge {
    vector<int> to; //{to_where, weight}
};

vector<int> dfs(vector<vector<Edge>> graph, int start = 0) {
    // initialize color array with -1
    vector<int> color(graph.size(), -1);
    stack<int> st;
    st.push(start);
    color[start] = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            //access graph[i] edges
            int v = graph[u][i].to[0];
            int w = graph[u][i].to[1];
            if (color[v] < 0) {
                // it's unvisited
                if (w % 2 == 0) {
                    color[v] = color[u];
                }
                else {
                    color[v] = !color[u];
                }
                st.push(v);
            }
        }
    }
    return color;
}
int main() {
    int N; cin >> N;
    vector<vector<Edge>> graph(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        Edge uv = { {v,w} };
        Edge vu = { {u,w} };
        graph[u].push_back(uv);
        graph[v].push_back(vu);
    }
    vi ans = dfs(graph, 0);
    for (auto& val : ans) {
        cout << val << endl;
    }
}