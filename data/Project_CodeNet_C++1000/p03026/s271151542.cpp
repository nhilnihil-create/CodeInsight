#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

void dfs(Vvec<int>& graph, int from, int tmp, int& index, 
    vector<int>& c, vector<int>& d)
{
    d[tmp] = c[index];
    index--;
    for(int& to: graph[tmp]){
        if(to != from) dfs(graph, tmp, to, index, c, d);
    }
}

int main()
{
    int N;
    cin >> N;
    Vvec<int> graph(N);
    for(int i=0; i<N-1; i++){
        int u, v;
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> c(N), d(N);
    for(int& x: c) cin >> x;
    sort(c.begin(), c.end());

    int index = N-1;
    dfs(graph, -1, 0, index, c, d);

    int score = 0;
    for(int i=0; i<N-1; i++) score += c[i];
    cout << score << endl;
    for(int i=0; i<N; i++) cout << d[i] << " "; cout << endl;
}