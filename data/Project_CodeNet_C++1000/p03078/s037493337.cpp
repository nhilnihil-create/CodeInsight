#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define yn(x, ok, ng) cout << ((x)?(ok):(ng)) << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;

// (sum, {x,y,z})
using Data = pair<ll, vi>;

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

vl N(3);
rep(i,3) cin >> N[i];
int K;
cin >> K;

vvl v(3);
rep(i,3) {
    v[i].resize(N[i]);
    rep(j,N[i]) cin >> v[i][j];
    sort(v[i].begin(), v[i].end(), greater<ll>());
}

priority_queue<Data> que;
set<Data> st;
que.push(Data(v[0][0] + v[1][0] + v[2][0], vi({0, 0, 0})));
rep(k,K) {
    auto d = que.top(); que.pop();
    cout << d.first << endl;

    // (A[x],B[y],C[z])をみたときに
    // (A[x+1],B[y],C[z]), (A[x],B[y+1],C[z]),(A[x],B[y],C[z+1])を追加する
    rep(i,3) {
        // d.second[i] := i種類目(A,B,C)のケーキの現在のindex
        // N[i]より小さければインクリメントしたものを追加できる
        if(d.second[i] + 1 < N[i]) {
            ll sum = d.first - v[i][d.second[i]] + v[i][d.second[i] + 1];
            auto num = d.second;
            num[i]++;
            auto nd = Data(sum, num);
            //過去に追加したことあるものは除く
             if (!st.count(nd)) st.insert(nd), que.push(nd);
        }
    }
}

return 0;
}
