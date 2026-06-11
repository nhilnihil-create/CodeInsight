/*ILTH      ILTH            ILTHILTHILTH    ILTH        ILTH
  ILTH      ILTH                ILTH        ILTH        ILTH
  ILTH      ILTH                ILTH        ILTHILTHILTHILTH
  ILTH      ILTH                ILTH        ILTH        ILTH
  ILTH      ILTHILTHILTH        ILTH        ILTH        ILTH

  */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxN=65;

bool f[maxN];
int L,hs,cnt,d[maxN];
vector<int> h[maxN];
int dfs(int u){
    if (f[u]) return d[u];

    for (int i=0; i<h[u].size(); ++i){
        int v=h[u][i];
        cout << u << " " << v << " " << d[u] << "\n";
        d[u]+=dfs(v);
    }
    f[u]=true;
    return d[u];
}
int main()
{
    cin >> L;
    if (L==1){
        cout << "2 1\n1 2 0";
        return 0;
    }
    int mu=1;hs=1;
    while (mu*2<=L){
        mu*=2;
        hs++;
    }
    for (int i=1; i<=hs-1; ++i){
        h[i].pb(i+1);h[i].pb(i+1);cnt+=2;
        if (L & (1<<(i-1))) h[i].pb(hs),cnt++;
    }
    f[hs]=true;d[hs]=1;
    cout << hs << " " << cnt << "\n";
    dfs(1);
    return 0;
}
