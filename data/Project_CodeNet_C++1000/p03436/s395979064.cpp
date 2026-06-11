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
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}

char a[52][52];
ll dx[4] = {0,1,0,-1};
ll dy[4] = {1,0,-1,0};

int main(){FIN
    ll h,w;cin>>h>>w;
    ll white=0;
    REP(i,h)REP(j,w) {
        cin>>a[i][j];
        if (a[i][j]=='.') white++;
    }
    vvll dist(h, vll(w,-1));
    queue<P> q;
    q.push(make_pair(0,0));
    dist[0][0]=0;

    while(q.size()){
        P now=q.front();
        q.pop();
        ll x = now.first;
        ll y = now.second;
        REP(i,4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx>=h || nx<0 || ny>=w || ny<0) continue;
            if (dist[nx][ny]!=-1) continue;
            if (a[nx][ny]=='#') continue;
            dist[nx][ny] = dist[x][y]+1;
            q.push(make_pair(nx,ny));
        }
    }
    if (dist[h-1][w-1]==-1) cout<<-1<<endl;
    else cout<< white - dist[h-1][w-1]-1 <<endl;
    return 0;
}