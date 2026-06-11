#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n; cin >> n;
    vector<int> G[10005];
    int c[n];
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,n) cin >> c[i];
    sort(c,c+n); reverse(c,c+n);
    
    vector<P> v;
    rep(i,n) v.push_back(make_pair(G[i].size(),i));
    sort(all(v)); reverse(all(v));
    int ans[n];
    bool visit[n];
    rep(i,n) visit[i] = false;

    queue<int> q;
    q.push(v[0].second);
    int cnt = 0,sum = 0;
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        visit[tmp] = true;
        ans[tmp] = c[cnt];
        cnt++;
        for(auto i : G[tmp]){
            if(!visit[i]) q.push(i);
        }
    }
    for(int i = 1; i < n; i++) sum += c[i];

    cout << sum << endl;
    rep(i,n) cout << ans[i] << ' ';
}