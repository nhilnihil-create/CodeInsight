#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

const int N = 1e5+5;
vi g[N];
vi dp(N,-1);
int n,m;

int go(int node){

    if(dp[node]!=-1){
        return dp[node];
    }

    bool leaf = 1;
    int best = 0;
    for(auto nbr : g[node]){
        leaf = 0;
        best = max(best, go(nbr));
    }

    return dp[node] = (leaf ? 0 : 1 + best);
}

void solve() {

    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
    }

    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,go(i));
    }

    cout << ans << endl;

}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
