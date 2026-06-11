#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
#include<deque>
#include<chrono>
using namespace std;
#define pi 3.141592653589793238


#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>
typedef vector<ll> vi;
typedef vector<vi> vvi;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 1e5 + 1;
vector<pair<ll,ll>> adj[N];
ll color[N];
bool visited[N];
void dfs(ll a, ll dist){
    visited[a] = true;
    for(auto u : adj[a]){
        if(!visited[u.ff]){
            ll bc;
            bc = dist + u.ss;
            if(bc % 2 == 0){
                color[u.ff] = 0;
            }
            else{
                color[u.ff] = 1;
            }
            dfs(u.ff, bc);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    
    //cin >> T;
    while (T--) {
        ll n;
        ll a ,b, c;
        cin >> n;
        for(i = 0; i < n - 1; i++){
            cin >> a >> b >> c;
            adj[a].pb({b, c});
            adj[b].pb({a, c});
        }
        color[1] = 0;
        dfs(1, 0);
        for(i = 1; i <= n; i++){
            cout << color[i] << endl;
        }
    }

    return 0;
}
