#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;

ll N,C;
ll d[35][35];
ll c[505][505];
ll t[3][30];
int main(){FIN
    cin>>N>>C;
    ll ans = inf;
    REP(i,C) REP(j,C) cin>>d[i][j];
    REP(i,N) REP(j,N) {
        cin>>c[i][j];
        t[(i+j)%3][c[i][j]-1]++;
    }
    REP(i,C){
        REP(j,C){
            if (i!=j) REP(k,C){
                if(i!=k && j!=k){
                    ll tt=0;
                    REP(l,C) tt += d[l][i] * t[0][l];
                    REP(l,C) tt += d[l][j] * t[1][l];
                    REP(l,C) tt += d[l][k] * t[2][l];
                    ans = min(ans, tt);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}