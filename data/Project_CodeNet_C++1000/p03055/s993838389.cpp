#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N;
    cin >> N;
    vector<int> edge[N+1];
    queue<int> que;
    int dist[N+1];
    int Mdist;
    bool used[N+1];
    fill_n(used, N+1, false);
    rep(i, N-1){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dist[1] = 0;
    Mdist = 0;
    int pos = 1;
    que.push(1);
    used[1] = true;
    while(!que.empty()){
        int i = que.front();
        que.pop();
        rep(j, edge[i].size()){
            int k = edge[i][j];
            if(!used[k]){
                used[k] = true;
                que.push(k);
                dist[k] = dist[i]+1;
                if(dist[k] > Mdist){
                    pos = k;
                    Mdist = dist[k];
                }
            }
        }
    }
    dist[pos] = 0;
    Mdist = 0;
    que.push(pos);
  	fill_n(used, N+1, false);
    used[pos] = true;
    while(!que.empty()){
        int i = que.front();
        que.pop();
        rep(j, edge[i].size()){
            int k = edge[i][j];
            if(!used[k]){
                used[k] = true;
                que.push(k);
                dist[k] = dist[i]+1;
                if(dist[k] > Mdist){
                    Mdist = dist[k];
                }
            }
        }
    }
    if(Mdist%3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
}