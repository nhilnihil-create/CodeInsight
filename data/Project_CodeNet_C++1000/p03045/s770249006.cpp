#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1e5+10;
const int mod = 1e9+7;

using namespace std;

int p[maxn],sz[maxn],ans;

void start(){
    for(int i=0;i<maxn;++i){
        p[i] = i;
        sz[i] = 1;
    }
}

int find_set(int x){
    return p[x] = (p[x] == x ? x:find_set(p[x]));
}

void union_set(int x,int y){
    x = find_set(x);
    y = find_set(y);
    if(x==y) return;
    if(sz[x] > sz[y]) swap(x,y);
    p[x]=y;
    sz[y]+=sz[x];
    --ans;
}

void solve(){
	int n,m;
    cin >> n >> m;
    ans=n;
    for(int i=0;i<m;++i){ 
        int x,y,z;
        cin >> x >> y >> z;
        union_set(x,y);
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    // cin >> t;

    start();

    while(t--){
    	solve();
    }

    return 0;
}