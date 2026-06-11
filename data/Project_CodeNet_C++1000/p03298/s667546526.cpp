#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <map>

#define fir first
#define sec second
#define sz(s) (s).size()
#define pb push_back
#define get(n) scanf("%d",&n);
#define gets(s) string s;cin >> (s);
#define prfi(n) printf("%d", &n);
#define prfd(n) printf("%lf", &n);
#define All(s) (s).begin(), (s).end()
#define rep(i,j) for(int (i)=0;(i)<(j);(i)++)
#define For(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define repd(i,j) for(int (i)=(j);(i)>=0;(i)--)
#define Ford(i,j,k) for(int (i)=(j);i>=(k);i--)
#define vfor(c,v) for(auto (c): v)
#define dump(x)  std::cout << #x << " = " << (x) << std::endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using ll = long long;
using pii = std::pair<int,int>;
using pll = std::pair<ll, ll>;
using pss = std::pair<std::string, std::string>;
using vi = std::vector<int> ;
using vvi = std::vector<vi> ;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vd = std::vector<double> ;
using vvd = std::vector<vd> ;
using qi = std::queue<int> ;
using vpii = std::vector<std::pair<int, int> >;
using vpll = std::vector<pll>;
using namespace std;

const int Mod = (1e9) + 7;
const int max_n = 3 * (1e5) + 1;
const int max_m = 83 * (1e5) + 1;
const int INF = 1e9 + 19;
const ll INFL = 1e18 + 19;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
//_____________________________________Templates_________________________________________//

template<class T1, class T2> inline void chmin(T1 &a, T2 b){if(a > b) a = b;}
template<class T1, class T2> inline void chmax(T1 &a, T2 b){if(a < b) a = b;}

//mainly use for dynamic prog
template<class T1, class T2>
void update(T1 &a, T2 b){
  a += b;
  if(a > Mod) a %= Mod;
}

inline void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

inline void OUT(void){
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

bool pairsort(pll pl, pll pr){
  if(pl.first == pr.first)return pl.second > pr.second;
  return pl.first < pr.first;
}
//_____________________　following sorce code_________________________//
int n,m,k;
vvi dp;
string S;
vll cost(1 << 16);
int a,b,c;
int h,w;
vi v;
vll u;

bool check(){
}

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  IN(n,S);
  map<pss,int> mp;
  rep(i,1<<n){
    string A = "", B = "";
    rep(j,n){
      if(i &(1 << j))A+= S[j];
    }
    repd(j,n-1){
      if(!(i & (1 << j)))B += S[j];
    }
    mp[pss(A,B)]++;
  }

  ll ans = 0;
  rep(i,1<<n){
    string A = "", B = "";
    rep(j,n){
      if(i & (1 << j))A += S[n+j];
    }
    repd(j,n-1){
      if( !(i & (1 << j)))B += S[n+j];
    }
    ans += mp[pss(B,A)];
  }
  cout << ans << endl;
  //cout << fixed << setprecision(15) << ans << endl;
  return 0;
}