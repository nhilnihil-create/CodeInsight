#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;

vector<pii> List[90005];

int main()
{
    int H,W,D;
    cin >> H >> W >> D;
    vvi a(H,vi(W));
    vector<pii> data(H*W);
    rep(h,H) rep(w,W) {
        cin >> a[h][w];
        a[h][w]--;
        data[a[h][w]] = pii(h,w);
    }
    rep(i,H*W) List[i%D].emplace_back(data[i]);//List[x]:= 余りxである整数の場所が小さい順に並ぶ

    vvi d(D);
    vvi sd(D);
    rep(i,D) {
        if(List[i].empty()) continue;
        int n = List[i].size() - 1;
        d[i].resize(n);
        sd[i].resize(n+1);
        rep(j,n) {
            int uh = List[i][j].first; int uw = List[i][j].second;
            int vh = List[i][j+1].first; int vw = List[i][j+1].second;
            d[i][j] = abs(uh-vh) + abs(uw-vw);
            sd[i][j+1] = sd[i][j] + d[i][j];
        }
    }

    int Q;
    cin >> Q;
    rep(q,Q) {
        int L,R;
        cin >> L >> R;
        L--; R--;
        cout << sd[R%D][R/D] - sd[L%D][L/D] << endl;
    }
    return 0;
}