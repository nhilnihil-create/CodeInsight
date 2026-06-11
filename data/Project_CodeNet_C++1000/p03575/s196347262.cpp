#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct UnionFind
{
    vector<long long> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    long long root(long long x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(long long x, long long y)
    {                           // xとyの木を併合
        long long rx = root(x); //xの根をrx
        long long ry = root(y); //yの根をry
        if (rx == ry)
            return;   //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(long long x, long long y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N,M,ans=0;
    string S;
    cin >> N>>M;

    vector<ll> a(M),b(M);

    REP(i,M){
        cin >> a.at(i) >> b.at(i);
    }

    

    REP(i,M){
        UnionFind tree(N + 1);
        REP(j,M){
            if(i==j){

            }
            else{
                tree.unite(a.at(j), b.at(j));
            }
        }

        ll start = tree.root(1);
        for (ll j = 2; j <= N; j++) {
            ll tmp = tree.root(j);
            if(!(tmp==start)){
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}
