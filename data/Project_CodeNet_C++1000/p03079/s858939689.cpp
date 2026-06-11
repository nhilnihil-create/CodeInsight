#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repp(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)
#define ALL(a) (a).begin(), (a).end()
#define p(a, b) printf(a, b);
#define c(s) cout << (s) << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define cyn(c) cout << (c ? "Yes" : "No") << endl;
#define cYN(c) cout << (c ? "YES" : "NO") << endl;
#define pyn(c) printf("%s\n", c ? "Yes" : "No");
#define pYN(c) printf("%s\n", c ? "YES" : "NO");
#define INF 1e18
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> P;
template <class T>
bool contain(const std::string &s, const T &v)
{
  return s.find(v) != std::string::npos;
}
ULL mod = 1e9 + 7;

map<ULL, ULL> prime_factor(ULL n)
{
  map<ULL, ULL> ret;
  for (ULL i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1)
    ret[n] = 1;
  return ret;
}

int N,W;
int w[1005],v[1005];
int dp[1005][1005];
void knapsack_dp(){
  rrep(i,N-1,0){
    rep(j,W+1){
      if(j<w[i]){
        dp[i][j] = dp[i+1][j];
      }else{
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
}
// int cnt=0; char c;
// while (cin >> W){
//   if(W==0) break;
//   cin>>N;
//   rep(i,N)cin>>v[i]>>c>>w[i];
//   knapsack_dp();

//   int value,weight;
//   value = weight = 0;
//   rep(i,W+1){
//     if (value < dp[0][i]){
//       value = dp[0][i];
//       weight = i;
//     }
//   }

//   cout << "Case " << ++cnt << ":" << endl;
//   cout << value << endl;
//   cout << weight << endl;

//   memset(w,0,sizeof(w));
//   memset(v,0,sizeof(v));
//   memset(dp,0,sizeof(dp));
// }

int main(){
    int a,b,c; cin>>a>>b>>c;
    if(a==b&&b==c){
      yes;
    }else{
      no;
    }

}
