#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

ll N, M;
vector<ll> V(50, 0);
vector<vector<ll>> D(50, vector<ll>(50, 0));

void DFS(ll num) {
        if (V[num] == 1) return;
        V[num] = 1;

        rep(i,N) {
                if (num == i) continue;
                if (D[num][i] == 1) {
                        DFS(i);
                }
        }
}

int main()
{
        cin >> N >> M;
        vector<ll> a(M, 0);
        vector<ll> b(M, 0);
        rep(i,M) {
                ll aa, bb; cin >> aa >> bb;
                a[i] = aa-1; b[i] = bb-1;
                D[a[i]][b[i]] = 1;
                D[b[i]][a[i]] = 1;
        }
        ll ans = 0;
        rep(i, M) {
                D[a[i]][b[i]] = 0; D[b[i]][a[i]] = 0;
                rep(j,N) V[j] = 0;
                DFS(0);
                bool bridge = false;
                rep(j,N) {
                        if (V[j] == 0) {
                                bridge = true;
                                break;
                        }
                }
                if (bridge) ans++;
                D[a[i]][b[i]] = 1; D[b[i]][a[i]] = 1;
        }
        cout << ans << endl;
}
