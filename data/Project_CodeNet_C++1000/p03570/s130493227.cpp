#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int MAX_N = 200010;
ll INF = 1LL<<60;
vector<vector<P>> edges(MAX_N);
vector<ll> dist(MAX_N,INF);

void dijkstra(int s) {
    priority_queue<P,vector<P>,greater<P>> que;
    dist[s] = 0;
    que.push(P(0,s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v =  p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0;i < edges[v].size();++i) {
            P e = edges[v][i];
            if (dist[e.first] > dist[v]+e.second) {
                dist[e.first] = dist[v]+e.second;
                que.push(P(dist[e.first],e.first));
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<int,int> mp;
    mp.reserve(200010);
    int t = 0;
    mp[0] = 0;
    for (int i = 0;i < n;++i) {
        t ^= (1<<(s[i]-'a'));
        for (int j = 0;j < 26;++j) if (mp.find(t^(1<<j)) != mp.end()) {
            edges[mp[t^(1<<j)]].push_back((P(i+1,1)));
        }
        if (mp.find(t) != mp.end()) edges[mp[t]].push_back(P(i+1,0));
        mp[t] = i+1;
    }
    for (int i = 0;i < n;++i) if (edges[i].empty()) edges[i].push_back(P(i+1,1));
    dijkstra(0);
    cout << max(1LL,dist[n]) << endl;
    /*
    for (int i = 0;i < n;++i) {
        for (P p : edges[i]) cout << p.first << " ";
        cout << endl;
    }
    p_ary(dist,0,n+1,i);
    */
    return 0;
}