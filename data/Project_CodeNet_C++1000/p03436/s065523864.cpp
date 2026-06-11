//include
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
//------------------------------------------
//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<long long> VL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef vector<VL> VVL;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
//------------------------------------------
//comparison
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define C_MIN(a, b) ((a)<(b)?(a):(b))
#define C_ABS(a, b) ((a)<(b)?(b)-(a):(a)-(b))
//------------------------------------------
//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define SUMI(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SUMD(obj) accumulate((obj).begin(), (obj).end(), 0.)
#define SUML(obj) accumulate((obj).begin(), (obj).end(), 0ll)
#define UB(obj, n) upper_bound((obj).begin(), (obj).end(), n)
#define LB(obj, n) lower_bound((obj).begin(), (obj).end(), n)
#define BS(v, n) binary_search(ALL(v), (n))
#define PB push_back
#define MP make_pair
//------------------------------------------
//repetition
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORL(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORL(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPL(i, n) for(ll i=0;i<ll(n);++i)
#define RREPL(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define FOREACH(x, v) for(auto &(x) : (v))
#define FORITER(x, v) for(auto (x) = (v).begin(); (x) != (v).end(); ++(x))
//------------------------------------------
//input output
#define GL(s) getline(cin, (s))
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define IN(...) GET_MACRO(__VA_ARGS__, IN3, IN2, IN1)(__VA_ARGS__)
#define IN1(n) std::cin>>(n);
#define IN2(n,m) std::cin>>(n)>>(m);
#define IN3(n,m,l) std::cin>>(n)>>(m)>>(l);
#define OUT(d) std::cout<<(d);
#define OUT_L(d) std::cout<<(d)<<endl;
#define OUT_Y std::cout<<"Yes"<<endl;
#define OUT_N std::cout<<"No"<<endl;
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<(d);
#define EL() std::cout << "\n";
//------------------------------------------
//constant
#define MAX 200000
#define MOD 1000000007
#define INF 1<<29
//------------------------------------------

//数値・文字列
inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
inline ll toLongLong(string s) {
    ll v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}
inline VC toVC(string s) {
    VC data(s.begin(), s.end());
    return data;
}
//------------------------------------------
//extended permutation combination
// possible implementation introduced at http://en.cppreference.com/w/cpp/algorithm/rotate with slight modification to handle parted ranges
template<typename FI>
void parted_rotate(FI first1, FI last1, FI first2, FI last2){
 if(first1 == last1 || first2 == last2) return;
 FI next = first2;
 while (first1 != next) {
  std::iter_swap(first1++, next++);
  if(first1 == last1) first1 = first2;
  if (next == last2) {
   next = first2;
  } else if (first1 == first2) {
   first2 = next;
  }
 }
}
template<typename BI>
bool next_combination_imp(BI first1, BI last1, BI first2, BI last2){
 if(first1 == last1 || first2 == last2) return false;
 auto target = last1; --target;
 auto last_elem = last2; --last_elem;
 // find right-most incrementable element: target
 while(target != first1 && !(*target < *last_elem)) --target;
 if(target == first1 && !(*target < *last_elem)) {
  parted_rotate(first1, last1, first2, last2);
  return false;
 }
 // find the next value to be incremented: *next
 auto next = first2;
 while(!(*target < *next)) ++next;
 std::iter_swap(target++, next++);
 parted_rotate(target, last1, next, last2);
 return true;
}
// INVARIANT: is_sorted(first, mid) && is_sorted(mid, last)
template<typename BI>
inline bool next_combination(BI first, BI mid, BI last){
 return next_combination_imp(first, mid, mid, last);
}
// INVARIANT: is_sorted(first, mid) && is_sorted(mid, last)
template<typename BI>
inline bool prev_combination(BI first, BI mid, BI last){
 return next_combination_imp(mid, last, first, mid);
}
//------------------------------------------
//other functions
//------------------------------------------
// a^n mod を二分累乗法で計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
// a^{-1} mod を計算する
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
long long moddiv(long long a, long long b, long long mod){
    a %= mod;
    return a*modinv(b, mod) % mod;
}
//任意の二項係数nCkをO(n)->O(1)で求める
long long fac[MAX], finv[MAX], inv[MAX];

 // テーブルを作る前処理
void nCkinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

 // 二項係数計算
long long nCk(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
} 

//最大公約数
template<class T>
inline T GCD(const T x, const T y) {
    if (x < 0)return GCD(-x, y);
    if (y < 0)return GCD(x, -y);
    return (!y) ? x : GCD(y, x % y);
}

//最小公倍数
template<class T>
inline T LCM(const T x, const T y) {
    if (x < 0)return LCM(-x, y);
    if (y < 0)return LCM(x, -y);
    return x * (y / GCD(x, y));
}
//探索系
void dfs(VVI& G,VI& O,VI& counter,int u){
    FOREACH(v,G[u]){
        if(counter[v]!=-1) continue;
        counter[v]=counter[u]+O[v];
        dfs(G,O,counter,v);
    }
    return;
}
int bfs(VVI& M){
    const int dx[4]={-1,0,1,0};
    const int dy[4]={0,-1,0,1};
    int h=M.size(),w=M[0].size();   
    queue<PI> q;
    q.push({0,0});
    while(!q.empty()){
        PI u = q.front();
        q.pop();
        REP(i,4){
            PI next={u.first+dx[i],u.second+dy[i]};
            if(next.first<0||next.first>=h||next.second<0||next.second>=w){
                continue;
            }else if(M[next.first][next.second]==0){
                M[next.first][next.second]=M[u.first][u.second]+1;
                q.push(next);
            }
        }
    };
    return M[h-1][w-1];
}
//-----------------------------------------
//memo-------------------------------------
/*
//尺取り法

//二分法
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}
// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    // ok と ng のどちらが大きいかわからないことを考慮
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}
//-----------------------------------------

*/
//main code--------------------------------
void _main(){ 
    ll h,w;IN(h,w)
    ll out=0;
    VVI M(h,VI(w,0));REP(i,h)REP(j,w){
        char s;IN(s)
        if(s=='#'){M[i][j]=1;out--;}
    }
    ll dist = bfs(M);
    out += h*w-dist-1;
    if(dist == 0) out=-1;
    OUT_L(out)
    cout<<endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    //nCkinit();
    _main();
    return 0;
}
