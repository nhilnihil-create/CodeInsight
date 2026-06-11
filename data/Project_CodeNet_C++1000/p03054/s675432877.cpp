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
typedef vector<int> vec;
typedef vector<string> svec;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
//#define int long long

//ゲームは後ろから！

void solve() {
    int H, W, N; cin >> H >> W >> N;
    int sr, sc; cin >> sr >> sc;
    sr --; sc --;
    string S, T; cin >> S >> T;
    int l = 0, r = W, d = 0, u = H;
    //[ , )区間で考えるのが分かりやすい
    per(i, N) {
        if(i != N - 1) {
            if(T[i] == 'L') {
                if(r != W)  r += 1;
            } else if(T[i] == 'R') {
                if(l != 0) l -= 1;
            } else if(T[i] == 'U') {
                if(u != H) u += 1;
            } else if(T[i] == 'D') {
                if(d != 0) d -= 1; 
            }
        }

        if(S[i] == 'L') {
            l += 1;
        } else if(S[i] == 'R') {
            r -= 1;
        } else if(S[i] == 'U') {
            d += 1;
        } else if(S[i] == 'D') {
            u -= 1; 
        }

        if(l >= r || d >= u) {
            cout << "NO" << endl;
            return;
        }
    }
    if(sr >= u || sr < d || sc >= r || sc < l) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
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