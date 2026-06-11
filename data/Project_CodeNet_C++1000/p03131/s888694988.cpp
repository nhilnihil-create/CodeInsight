 #include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#include <iomanip>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
int dx8[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy8[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dx4[4] = {1, 0, -1, 0};
int dy4[4] = {0, 1, 0, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };


int main() {
   ll K,A,B;
   cin >> K >> A >> B;
   if(B-A<=2 || K < A-1){
       fin(1+K);
   }else{
       //まずスタート一枚からAまで行く回数を出す
       //A枚まで増やす→B-A枚残りで増やし続けるにする
       
       
       ll sum=A;
       K-=A-1;
       
       if(K%2 == 1){
           //残りKが奇数回だったら
           sum++;
           K--;
       }
       sum += (B-A)*(K/2);
       fin(sum);
   }


}
    

