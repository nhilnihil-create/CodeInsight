#include <bits/stdc++.h>
#define int long long int
#define MOD(x) ((x % MOD_N) + MOD_N) % MOD_N
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define RFORE(i,a,b) for(int i=(b);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(c) (int)((c).size())
#define EACH(i,v) for(auto i=v.begin();i!=v.end();++i)
#define REACH(i,v) for(auto i=v.rbegin();i!=v.rend();++i)
#define LB(c,x) distance((c).begin(),lower_bound(ALL(c),x))
#define UB(c,x) distance((c).begin(),upper_bound(ALL(c),x))
#define COUNT(c,x) (upper_bound(ALL(c),x)-lower_bound(ALL(c),x))
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define COPY(c1,c2) copy(ALL(c1),(c2).begin())
#define EXIST(s,e) (bool)((s).find(e)!=(s).end())
#define PB push_back
#define MP make_pair
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;
#define NL cerr<<endl;
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>T sum(vector<T>&v){return accumulate(ALL(v),T());}
template<typename T>T sum(vector<T>&v,int a,int b){return accumulate(v.begin()+a,v.begin()+b,T());}
template<typename T>T max(vector<T>&v){return *max_element(ALL(v));}
template<typename T>T min(vector<T>&v){return *min_element(ALL(v));}
template<typename T>T max_index(vector<T>&v){return distance((v).begin(),max_element(ALL(v)));}
template<typename T>T min_index(vector<T>&v){return distance((v).begin(),min_element(ALL(v)));}

struct edge { int to, cost; };

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}

const int INF = 1e18;
const int MOD_N = 998244353;

vector<int> frac;
void init_frac(int N, int mod_n=MOD_N) {
   frac.resize(N+1);
   frac[0] = 1;
   for (int i = 1; i <= N; i++) {
      frac[i] = (frac[i-1] * i) % mod_n;
   }
}
int powM(int x, int n, int mod_n=MOD_N) {
   int res = 1;
   while (n > 0) {
      if ((n & 1) == 1) (res *= x) %= mod_n;
      (x *= x) %= mod_n;
      n >>= 1;
   }
   return res;
}
int inverseM(int x, int mod_n=MOD_N) {
   return powM(x, mod_n-2);
}
int comb(int n, int r, int mod_n=MOD_N) {
   if (n < 0 || n-r < 0 || r < 0) return 0;
   return (frac[n] * inverseM((frac[n-r]*frac[r]) % mod_n)) % mod_n;
}

signed main()
{
   int N, A, B, K;
   cin >> N >> A >> B >> K;

   init_frac(N);
   int ans = 0;
   FORE(x, 0, N) if ((K - A * x) % B == 0){
      int y = (K - A * x) / B;
      (ans += MOD(comb(N,x) * comb(N,y))) %= MOD_N;
   }
   cout << ans << endl;

   return 0;
}
