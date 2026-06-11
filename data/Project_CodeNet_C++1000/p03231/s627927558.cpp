#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

ll gcd(ll x, ll y){
    return y ? gcd(y, x%y) : x;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    ll g = gcd(N, M);
    ll ans = N / g * M;
    N /= g, M /= g;
    bool ok = true;
    REP(i,g){
        if(S[i*N] != T[i*M]) ok = false;
    }
    if(ok) cout << ans << endl;
    else cout << -1 << endl;
}