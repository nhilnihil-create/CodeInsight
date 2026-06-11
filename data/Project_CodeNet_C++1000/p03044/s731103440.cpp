#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)
vvii adj;

void dijkstra(ll s, vvii adj, vi &d, vi &p) {
    ll n = adj.size();
    d.assign(n, LLMAX);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().S;
        ll d_v = q.top().F;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.F;
            ll len = edge.S;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
vi d,p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,y,z;
    cin>>n;
    adj.resize(n);
    for(int i=0;i<n-1;i++){
        cin>>x>>y>>z;x--;y--;
        adj[x].pb(mp(y,z));
        adj[y].pb(mp(x,z));
    }
    dijkstra(0,adj,d,p);
    for(int i=0;i<n;i++){
        if(d[i]%2){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    

    

    return 0;
}