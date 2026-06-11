#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define int long long

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

int N, M;
vector<int> G[100100];

int color[100100];

bool dfs(int v, int c) {
    color[v] = c;
    for(auto u : G[v]) {
        if(color[u] == c) return false;
        if(color[u] == -1 && !dfs(u, 1 - c)) return false;
    }
    return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> N >> M;
    rep(i, M) {
        int a, b; cin >> a >> b;
        a --; b --;
        G[a].pb(b); G[b].pb(a);
    }
    memset(color, -1, sizeof(color));
    if(!dfs(0, 1)) {
        cout << N * (N - 1) / 2 - M << endl;
        return 0;
    } else {
        int cnt0 = 0, cnt1 = 0;
        rep(i, N) {
            if(color[i] == 0) cnt0 ++;
            else if(color[i] == 1) cnt1 ++;
        }
        cout << cnt1 * cnt0 - M << endl;
    }
	return 0;
}