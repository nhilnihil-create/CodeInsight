#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
//constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
ll INF = 6001001001001001001;
long double EPS = 1e-6;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll H,W,N;
ll sy,sx;
string S,T;

int main(){
   cin >> H >> W >> N >> sy >> sx >> S >> T;
   ll u = sy,d = sy,l = sx,r = sx;
   bool flag = 0;
   rep(i,N){
       if(S[i] == 'U') u--;
       if(S[i] == 'D') d++;
       if(S[i] == 'L') l--;
       if(S[i] == 'R') r++;
       if(u == 0 || d == H + 1 || l == 0 || r == W + 1){
           cout << "NO" << endl;
           return 0;
       }
       if(T[i] == 'U' && d > 1) d--;
       if(T[i] == 'D' && u < H) u++;
       if(T[i] == 'L' && r > 1) r--;
       if(T[i] == 'R' && l < W) l++;
   }
   cout << "YES" << endl;
}