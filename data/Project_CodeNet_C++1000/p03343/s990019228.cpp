#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
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
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = mod * mod;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<string> svec;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
//#define int long long

void solve() {
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(N), B(N);
    rep(i, N) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(all(B));
    int ans = B[Q - 1] - B[0];
    rep(i, N) {
        int X = A[i];
        vector<int> vec, res;
        rep(j, N) {
            if(A[j] >= X) {
                vec.pb(A[j]);
            } 
            if(A[j] < X || j == N - 1) {
                sort(all(vec));
                int M = vec.size();
                rep(k, M - K + 1) {
                    res.pb(vec[k]);
                }
                vec.resize(0);
            }
        }
        sort(all(res));
        if(Q > res.size()) continue;
        int Y = res[Q - 1];
        int ret = Y - X;
        ans = min(ans, ret);
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}