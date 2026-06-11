#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m; cin >> n >> m;
    int visited[n];
    rep(i,n) visited[i] = 0;
    // pair<int, int> edge[n+m-1];
    vector<int> edge[n];
    rep(i, n+m-1)
    {
        int a, b; cin >> a >> b;
        a--;
        b--;
        // edge[i] = make_pair(a,b);
        edge[a].push_back(b);
        visited[b]++;
    }
    int par = inf;
    rep(i,n)
    {
        if (!visited[i]) par = i;
    }

    // bfs
    int parents[n];
    queue<int> que;
    que.push(par);
    parents[par] = -1;
    while(!que.empty())
    {
        int now_at = que.front();
        que.pop();
        for(auto iter=edge[now_at].begin(); iter!=edge[now_at].end();iter++)
        {
            parents[*iter] = now_at;
            visited[*iter]--;
            if (visited[*iter]==0)
            {
                que.push(*iter);
            }
        }
    }
    rep(i,n)
    {
        cout << parents[i]+1 << endl;
    }
}
