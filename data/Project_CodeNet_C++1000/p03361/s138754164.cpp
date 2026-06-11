#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

void solve(){
    int H, W;
    cin >> H >> W;
    vector<string> fi(H);
    REP(i,H) cin >> fi[i];
    REP(i,H) REP(j,W) if(fi[i][j] == '#'){
        bool ok = false;
        REP(d, 4){
            int nh = i + dx[d], nw = j + dy[d];
            if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if(fi[nh][nw] == '#') ok = true;
        }
        if(!ok){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}
