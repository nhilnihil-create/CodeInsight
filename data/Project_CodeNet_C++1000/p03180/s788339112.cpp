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
#define sz(s) (s).size();
#define pb push_back
#define get(n) scanf("%d",&n);
#define gets(s) string s;cin >> (s);
#define prfi(n) printf("%d", &n);
#define prfd(n) printf("%lf", &n);
#define All(s) (s).begin(), (s).end()
#define rep(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define rep0(i,j) for(int (i)=0;(i)<(j);(i)++)
#define repdown(i, j, k) for(int (i)=(j);(i)>=(k);(i)--)
#define repdown0(i,j) for(int (i)=(j);i>=0;i--)
#define dump(x)  std::cout << #x << " = " << (x) << std::endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using ll = long long;
using vi = std::vector<int> ;
using vvi = std::vector<vi> ;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vd = std::vector<double> ;
using vvd = std::vector<vd> ;
using qi = std::queue<int> ;
using vpii = std::vector<std::pair<int, int> >;
using namespace std;

const int Mod = (1e9) + 7;
const int max_n = 3 * (1e5) + 1;
const int max_m = 83 * (1e5) + 1;
const int INF = 10241024;
const ll INFL = (1ll << 62) - 1;

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

//_____________________array calc____________________________________//
/*
vvi mul(vvi &A, vvi &B){
  vvi C(A.size(), vi(B.size()))
  rep(i,A.size()){
    rep(j,B.size()){
      rep(k,B[0].size()){
        C[i][j] = (C[i][j] A[i][k] + B[k][j]) % Mod;
      }
    }
  }

  return C;
}

vvi pow(vvi A, ll n){
  vvi B(A.size(), vi(A.size()));
  rep(i=0;i<A.size();i++){
    B[i][i] = 1;
  }

  while (n >0){
    if (n & 1) B = mul(B, A);
    A = mul(A, A);
    n = n >> 1;
  }
  return B;
}
*/
//_____________________Bynary Indexed Tree __________________________//
/*
struct BIT{
  #define bs (1 << 20)
  int bit[bs];

  int sum (int i){
    int s = 0;
    while(i > 0){
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int x){
    while(i <= n){
      bit[i] += x;
      i += i & -i;
    }
  }
}
*/

//____________________RMQ____________________________//
/*struct RMQ{
  #define s (1 << 20)
  ll dat[s];
  int n;

  void init(){
    memset(dat, -1e10, sizeof(dat));
  }

  void upd(int k, ll a){
    k += s/2 - 1;
    dat[k] = a;
    while(k > 0){
      k = (k -1) /2;
      dat[k] = max(dat[k*2+1], dat[k*2+2]);
    }
  }

  ll query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return -1e8;
    if( a <= l && r <= b)return dat[k];
    else 
    {
      ll vl = query(a, b, k*2+1, l, (l+r)/2);
      ll vr = query(a, b, k*2+2, (l+r)/2, r);
      return max(vl, vr);
    }
  }

  void Debug(int a){
    a += s/2 - 1;
    rep(i,s/2 - 1,a){
      dump(dat[i]);
    }
  }
};
*/
//_____________________　following sorce code_________________________//
int n,m,k,x,y;
//vvll dp(400, vll(400));
vll dp(1 << 16, -1e18);
string s;
vvll v(16, vll(16));
vll cost(1 << 16);
ll ans = 0;

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  IN(n);
  rep0(i,n)rep0(j,n)IN(v[i][j]);

  ll s = (1 << n);
  rep0(i,s){
    rep0(j,n){
      rep(k,j+1,n-1){
        if(i&(1<<j))
        {
          if(i&(1<<k))
          {
            cost[i] += v[j][k];
          }
        }
      }
    }
  }

  dp[0] = 0;
  rep(i,1,s-1){
    for(int j=i;;j=(j-1)&i){
      chmax(dp[i], dp[i^j]+cost[j]);
      if(j==0)break;
    }
  }

  OUT(dp[s-1]);
  return 0;
}