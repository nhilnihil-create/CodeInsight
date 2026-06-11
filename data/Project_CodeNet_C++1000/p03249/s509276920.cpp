#include "bits/stdc++.h"
using namespace std;
#define int long long
#define ll long long


int n,m;
const int Max = (int)1e5+1;
vector<int> adj[Max];
bool visited[Max];
int parent[Max];
int numNodes[Max], sizes[Max];
int subtreeSize[Max] = {0};
ll sum1[Max], sum2[Max];

void dfs(int node) {
    visited[node] = true;
    numNodes[node] = 1;
    sum1[node] = 0;
    for(int to : adj[node]) {
        if(!visited[to]) {
            dfs(to);
            numNodes[node] += numNodes[to];
            sum1[node] += sum1[to] + (ll)numNodes[to];
        }
    }
}

void bfs(int start, ll treeSize) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    sum2[start] = sum1[start];
    while(!q.empty()) {
        int parent = q.front();
        q.pop();
        for(int node : adj[parent]) {
            if(!visited[node]) {
                q.push(node);
                visited[node] = true;
                sum2[node] = sum1[node];
                sum2[node] += sum2[parent]-sum1[node]-(ll)numNodes[node];
                sum2[node] += treeSize-(ll)numNodes[node];
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fill(subtreeSize, subtreeSize+n, 1);
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    map<int, int> toNode;
    for(int i = 0; i < n; ++i) {
        toNode[arr[i].first] = i;
    }
    
    //subtreeSize
    vector<pair<int, int>> edges;
    for(int i = n-1; i > 0; --i) {
        int nextSize = arr[i].first + 2*subtreeSize[i] - n;
        if(!toNode.count(nextSize)) {
            cout << "-1\n";
            return 0;
        }
        int par = toNode[nextSize];
        adj[par].push_back(i);
        adj[i].push_back(par);
        edges.push_back({par, i});
        subtreeSize[par] += subtreeSize[i];
    }
    fill(visited, visited+n, false);
    dfs(0);
    fill(visited, visited+n, false);
    bfs(0, n);
    for(int i = 0; i < n; ++i) {
        if(sum2[i] != arr[i].first) {
            cout << "-1\n";
            return 0;
        }
    }
    for(auto &p : edges) {
        cout << arr[p.first].second << ' ' << arr[p.second].second << '\n';
    }
    return 0;
}














