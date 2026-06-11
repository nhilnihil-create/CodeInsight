#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


bool solve(int N, int M, string& s, vi& a, vi& b) {
    vvi next(N);
    vi a_side(N,0), b_side(N,0);

    rep(i,M) {
        int u = a[i], v = b[i];
        bool cu = (s[u] == 'A'), cv = (s[v] == 'A');
        if (cv) ++a_side[u];
        else    ++b_side[u];
        next[u].pb(v);

        if (u != v) {
            if (cu) ++a_side[v];
            else    ++b_side[v];
            next[v].pb(u);
        }
    }

    queue<int> q;
    vector<bool> visited(N, false);
    int alive = N;



    rep(i,N){
        if (a_side[i]==0 || b_side[i]==0) {
            q.push(i);
        }
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (visited[u]) continue;

        bool cu = (s[u] == 'A');

        visited[u] = true;
        --alive;

        for (int v: next[u]) {
            if (visited[v]) continue;
            if (cu) --a_side[v];
            else    --b_side[v];
            if (a_side[v]==0 || b_side[v]==0) {
                q.push(v);
            }
        }
    }
    return alive > 0;
}

int main() {
    int N, M; cin >> N >> M;
    string s; cin >> s;
    vi a(M), b(M);
    rep(i,M) { scanf("%d %d", &a[i], &b[i]); --a[i]; --b[i]; }
    cout << (solve(N,M,s,a,b) ? "Yes":"No") << endl;
    return 0;
}
