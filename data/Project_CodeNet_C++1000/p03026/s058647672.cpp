#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll c[10001];
vector<int> g[10001];
ll s[10001];

int main(){
    int n;
    cin >> n;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll m = 0;
    rep(i, n) cin >> c[i], m += c[i];

    sort(c, c+n);
    reverse(c, c+n);

    m -= c[0];

    s[0] = c[0];

    queue<int> que;
    que.push(0);
    int i = 1;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : g[v]){
            if (s[nv] > 0) continue;
            s[nv] += c[i];
            i++;
            que.push(nv);
        }
    }

    cout << m << endl;
    rep(i, n) cout << s[i] << " ";
    cout << endl;

    return 0;
}
