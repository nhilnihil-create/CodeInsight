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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int N;

void Input() {

    cin >> N;
}



void Solve() {


    vector< pair<int, int> > blue;
    vector< pair<int, int> > red;



    for(int i = 0; i < N; i++) {

        int x, y;
        cin >> x >> y;
        red.push_back(make_pair(x,y));
    }

    for(int i = 0; i < N; i++) {

        int x, y;
        cin >> x >> y;
        blue.push_back(make_pair(x,y));
    }

    sort(blue.begin(), blue.end(),
            [](pair<int, int> l, pair<int, int> r) { return l.first < r.first; });
    sort(red.begin(), red.end(),
            [](pair<int, int> l, pair<int, int> r) { return l.second < r.second; });
    reverse(red.begin(), red.end());

    int cnt = 0;
    for(auto b : blue) {

        for(auto it = red.begin(); it != red.end(); ++it) {

            if(it->first < b.first && it->second < b.second) {

                cnt++;
                it->first = it->second = 300;
                break;
            }
        }
    }
    cout << cnt << endl;




}

int main() {

  cin.tie(0);
  ios::sync_with_stdio(false);
  Input();
  Solve();


  return 0;

}

