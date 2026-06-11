#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int main()
{
    int n,m; cin >> n >> m;
    int a[m],b[m];
    int ans = 0;
    rep(i,m) cin >> a[i] >> b[i];
    
    for(int i = 0; i < m; i++){
        vector<int> G[n];
        bool visit[n];
        rep(i,n) visit[i] = false;
        for(int j = 0; j < m; j++){
            if(i == j) continue;
            else{
                G[a[j]-1].push_back(b[j]-1);
                G[b[j]-1].push_back(a[j]-1);
            }
        }
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int now = que.front(); que.pop();
            visit[now] = true;
            for(auto next : G[now]){
                if(!visit[next]) que.push(next);
            }
        }
        rep(i,n){
            if(!visit[i]){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}