#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(0);
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MAXN 200005
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define pb push_back
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vii;
typedef vector <vi> matriz;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto timer_start = chrono::steady_clock::now().time_since_epoch().count();

int n;
int h[MAXN], v[MAXN];
int bit[MAXN];

void update(int x, int v){ 
    while(x < MAXN){
        bit[x] = max(bit[x], v);
        x += (x & -x); 
    }    
}

int query(int x){ 
    int sum = 0; 
    while(x > 0){
        sum = max(sum, bit[x]);
        x -= (x & -x); 
    }
    return sum;
}

int32_t main(){
    fastio
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> v[i];

    int res = 0;
    for(int i = 1; i <= n; i++){
        int atual = query(h[i] - 1);
        res = max(res, atual + v[i]);
        update(h[i], atual + v[i]);
    }
    cout << res << endl;

    return 0;
}