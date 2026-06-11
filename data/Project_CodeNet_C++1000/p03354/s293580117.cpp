#include <bits/stdc++.h> //library
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //for-loop (from 0)
#define reps(i,n) for(int i = 1; i <= (int)(n); i++) //for-loop (from 1)
#define all(x) (x).begin(),(x).end() //start-to-end iteration, mainly in upper_bound, lower_bound
#define SZ(x) ((int)(x).size()) //unsigned to signed

using namespace std;
using ll = long long; //long long
ll M = 1000000000 + 7;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; } //compare a,b and replace by greater
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; } //compare a,b and replace by smaller
ll qp(int a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; } //power
ll qp(int a, ll b, ll Mod = M) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%Mod; a = 1ll * a*a%Mod; } while (b >>= 1); return ans; } //power(mod)
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; } //gcd
int dx[4] = { 1,0,-1,0 }; //path
int dy[4] = { 0,1,0,-1 }; //path
ll RS(ll N, ll P, ll Mod = M) { if (P == 0)return 1; else if (P % 2 == 0) { ll sq = RS(N, P / 2, Mod); return sq*sq%Mod; } else { return N*RS(N, P - 1, Mod) % Mod; } } //power(mod)(repeat-square,fast)
ll nPr(ll n, ll r, ll Mod = M) { ll ans = 1; rep(i, r) { ans = ans * (n - i) % Mod; } return ans; } //permutation
ll nCr(ll n, ll r, ll Mod = M) { ll bunbo = 1; ll bunshi = 1; rep(i, r) { bunbo = bunbo * (i + 1) % Mod; bunshi = bunshi * (n - i) % Mod; } return bunshi * RS(bunbo, Mod - 2, Mod) % Mod; } //combination
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> par_num;

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        par_num.assign(N,1);
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;  //親がいない=自分自身が根
        return par[x] = root(par[x]); //xの親を、xの親の親につなぎ直す...つまり、ある木のノードを全て根につなぎ直す
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        par_num[root(rx)]++;
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
int main(void) {
  int N,M; cin >> N >> M;
  vector<int> nums(N);
  rep(i,N){
    cin >> nums[i];
    nums[i]--;
  }
  UnionFind tree(N);
  rep(i,M){
    int x,y; cin >> x >> y;
    tree.unite(x-1,y-1);
  }
  while(true){
    int flag = 0;
    rep(i,N){
      if (nums[i]!=i && tree.same(i,nums[i])){
        int temp = nums[nums[i]];
        nums[nums[i]] = nums[i];
        nums[i] = temp;
        flag = 1;
      }
    }
    if (flag==0) break;
  }
  int ans = 0;
  rep(i,N){
    if (nums[i]==i)ans++;
  }
  cout << ans << endl;
  return 0;
}