#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

vector<vector<ll>> graph;
vector<ll> depth;
void dfs(ll i, ll v) {
    if (depth[i] != -1) return;
    depth[i] = v;
    for (ll e : graph[i]) {
        dfs(e, v+1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    graph.assign(N, vector<ll>(N));
    depth.assign(N, -1);
    Rep (i, N-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll> c(N);
    ll M = 0;
    Rep (i, N) {
        cin >> c[i];
        
        M += c[i];
    }
    sort(c.begin(), c.end());
    M -= c.back();
    cout << M << "\n";

    dfs(0, 0);
    // Rep (i, N) {
    //     cout << depth[i] << "\n";
    // }

    set<pair<ll, ll>> ans;
    Rep (i, N) {
        ans.insert(make_pair(-depth[i], i));
    }

    vector<ll> output(N);
    ll i = 0;
    for (auto e : ans) {
        output[e.second] = c[i];
        i++;
    }

    for (ll e : output) {
        cout << e << " ";
    }

    cout << endl;
}