#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;


void solve() {
    int N, M;
    cin >> N >> M;
    
    string S;
    cin >> S;
    each(c, S)c -= 'A';
    vector<vi> deg(2, vi(N)), G(N);

    rep(i, M) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        deg[S[v]][u]++;
        deg[S[u]][v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int> Q;
    rep(i, N)if (!deg[0][i] || !deg[1][i]) {
        Q.push(i);
    }

    int cnt = N;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        each(v, G[u]) {
            if (deg[S[u]][v]-- == 1 && deg[1-S[u]][v] > 0) {
                Q.push(v);
            }
        }
        cnt--;
    }
    cout << (cnt > 0 ? "Yes" : "No") << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}