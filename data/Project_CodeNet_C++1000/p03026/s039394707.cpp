#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


void bfs(vector<vector<int>> &G, vector<int> &d, vector<int> &C) {
    int cnt = 1;
    d[0] = C[C.size()-1];
    queue<int> q;
    q.push(0);  
    while(!q.size()==0) {
        int s;
        s = q.front();
        q.pop();
        for (auto v: G[s]) {
            if (d[v]==-1) { 
                q.push(v);
                d[v] = C[C.size()-1-cnt];
                cnt ++;
            }
        }
    }
}

int main(){    
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    rep(i,N-1) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<int> C;
    rep(i,N) {
        int c;
        cin >> c;
        C.push_back(c);
    }
    sort(C.begin(),C.end());

    vector<int> d(N,-1);

    bfs(G,d,C);

    int ans;
    ans = 0;
    rep(i,N-1) {
        ans+=C[i];
    }
    cout << ans << endl;
    rep(i,N) {
        //ans = C[N-1-d[i]];
        cout << d[i] << " ";
        //cout << ans << " ";
    }
    cout << endl;

    
}
