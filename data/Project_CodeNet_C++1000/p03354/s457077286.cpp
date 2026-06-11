#include<bits/stdc++.h>

using namespace std;

#define EPS (1e-7)
#define INF (1e9)


typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
#define rep2(i, n) for(int i = 1; i <= (n); i++)
#define all(a) begin(a),end(a)
#define endl '\n'




int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


const int MOD = 1000000007;
const long double PI = (acos(-1));
const int MAX = 1000001;
long long fac[MAX], finv[MAX], inv[MAX];

//////////////////////////////////////////


void COMinit() {
   fac[0] = fac[1] = 1;
   finv[0] = finv[1] = 1;
   inv[1] = 1;
   for (int i = 2; i < MAX; i++){
       fac[i] = fac[i - 1] * i % MOD;
       inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
       finv[i] = finv[i - 1] * inv[i] % MOD;
   }
}

inline void init(vector<int>& uf) {

    iota(all(uf), 0);
}

inline int root(vector<int>& uf, int x) {

    if(uf[x] == x) {

        return x;
    }
    else {

        return uf[x] = root(uf, uf[x]);
    }
}

inline bool same(vector<int>& uf, int x, int y) {

    return root(uf, x) == root(uf, y);
}

inline void unite(vector<int>& uf, int x, int y) {

    x = root(uf, x);
    y = root(uf, y);

    if(x == y) return;

    uf[x] = y;
}

int N, M;

void Input() {

    cin >> N >> M;

}



void Solve() {


    vi p(N);

    vi uf(N+1);
    init(uf);

    for(int i = 0; i < N; i++) {

        cin >> p[i];
    }

    for(int i = 0; i < M; i++) {

        int x, y;
        cin >> x >> y;

        unite(uf, x, y);
    }

    int res = 0;
    for(int i = 0; i < N; i++) {

        if(same(uf, i+1, p[i])) res++;
    }

    cout << res << endl;
}

int main() {

  cin.tie(0);
  ios::sync_with_stdio(false);
  Input();
  Solve();


  return 0;

}

