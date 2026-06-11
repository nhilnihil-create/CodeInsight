#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;
int N,L;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N;
    vector<vector<int>> g(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    vector<int> v(N),dist(N);
    v[0] = 1;
    while(!q.empty()){
        int now = q.front();q.pop();
        for(auto x:g[now]){
            int next = x;
            if(v[next])continue;
            v[next] = 1;
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    int mx = 0;
    int p = 0;
    rep(i,N){
        if(mx < dist[i]){
            mx = dist[i];
            p = i;
        }
    }
    v = vector<int>(N,0);
    dist = vector<int> (N,0);
    q.push(p);
    v[p] = 1;
    while(!q.empty()){
        int now = q.front();q.pop();
        for(auto x:g[now]){
            int next = x;
            if(v[next])continue;
            v[next] = 1;
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    rep(i,N) L = max(L,dist[i]);
    if(L%3!=1)cout << "First" << endl;
    else cout << "Second" << endl;
}