#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 401;
const ll INF = 1e18;
ll dp[N][N];
ll acum[N];

ll f(int i, int j) {
    if (i == j) return 0;
    ll &r = dp[i][j];
    if (r != -1) return r;
    r = INF;
    forn(k, i, j) {
        ll a = f(i, k);
        ll b = f(k+1, j);
        ll cost = acum[j+1]-acum[i];
        r = min(r, a+b+cost);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    
    forn(i, 1, n+1) {
        cin >> acum[i];
        acum[i] += acum[i-1];
    }
    
    memset(dp, -1, sizeof dp);
    cout << f(0, n-1) << endl;
}
