#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define ld long double
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define pll pair<long long,long long>
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
long long MOD = 1000000007;
const long double pi = 3.1415926535897932;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define Grid vector<vector<char>>
#define vc vector<char>

//(mod m)でのaの逆元を計算する
//a/b(mod m)=a(mod m)*modinv(b,m)
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

//コンビネーション
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

//素因数分解
map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

//a^n modを計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// modnCr
ll modnCr(ll n, ll r, ll mod) {
  ll res = 1;
  rep (i, r) {
    res = res * (n - i) % mod * modpow(i + 1, mod - 2, mod) % mod;
  }
  return res;
}

//UF
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
//切り上げの割り算は(a + b - 1) / bでできる

//ここから
int main(){
    ll N;
    cin>>N;
    vvl AB(N,vl(0));
    vl C(N);
    rep(i,N-1){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        AB[a].pb(b);
        AB[b].pb(a);
    }
    rep(i,N)cin>>C[i];
    sort(all(C));
    reverse(all(C));
    vl Ans(N);
    ll res=0;
    queue<ll> q;
    vector<bool> visit(N,false);
    q.push(0);
    visit[0]=true;
    ll num=0;
    while (!q.empty())
    {
        ll f=q.front();
        Ans[f]=C[num];
        num++;
        q.pop();
        for(auto h:AB[f]){
            if(visit[h])continue;
            visit[h]=true;
            q.push(h);
        }
    }
    rep(i,N-1){
        res+=C[i+1];
    }
    cout<<res<<endl;
    rep(i,N){
        cout<<Ans[i];
        if(i==N-1)continue;
        cout<<' ';
    }
    cout<<endl;
}