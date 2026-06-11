#include<bits/stdc++.h>
using namespace std;
#define fast                         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int                          long long int
#define double                       long double
#define ff                           first
#define ss                           second
#define pb                           push_back
#define eb                           emplace_back
#define all(x)                       (x).begin(), (x).end()
#define sz(x)                        ((int)(x).size())
#define len(x)                       ((int)(x).length())
#define pii                          pair<int,int>
#define vi                            vector<int>
#define vd                           vector<double>
#define vs                            vector<string>
#define mp                          map<int,int>
#define ms(x,y)                     memset(x,y,sizeof(x))
#define ump                         unordered_map<int,int>

#define lb                            lower_bound
#define ub                            upper_bound
#define nx                            cout<<"\n";
#define inf                           9223372036854775807
#define PI                            3.14159265

const int MOD = 1e9 + 7;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
inline int add(int a, int b) {    return ((a % MOD) + (b % MOD)) % MOD;}

inline int multi(int a, int b) {   return ((a % MOD) * (b % MOD)) % MOD;}

inline int sub(int a, int b) {       a %= MOD; b %= MOD; a -= b; if (a < 0) a += MOD; return a;}

inline int power(int a, int b) {       a %= MOD; int res = 1; while (b > 0) {if (b & 1) {res = multi(res, a);} a = multi(a, a); b >>= 1;}  return res;}

bool isPrime(int  x) {      if (x <= 4 || x % 2 == 0 || x % 3 == 0) {return x == 2 || x == 3;} for (int i = 5; i * i <= x; i += 6) {if (x % i == 0 || x % (i + 2) == 0) { return 0;}} return 1;}

double dp[305][305][305];

double solve(int i, int j, int k, int n)
{
  if (i + j + k == 0)return 0;
  if (dp[i][j][k] > -0.5)return dp[i][j][k];
  double ans = 0;
  double m = (double)n / (i + j + k);
  if (i) {
    ans += (solve(i - 1, j, k, n) + 1) * ((double)i / n);
  }
  if (j) {
    ans += (solve(i + 1, j - 1, k, n) + 1) * ((double)j / n);
  }
  if (k) {
    ans += (solve(i, j + 1, k - 1, n) + 1) * ((double)k / n);
  }
  ans += (1 - (1.0 / m));
  ans *= m;
  return dp[i][j][k] = ans;
}
int32_t main()
{
  fast ;


  int n; cin >> n;
  int a(0), b(0), c(0);
  ms(dp, -1);
  for (int i = 0; i < n; i++)
  {
    int x; cin >> x;
    if (x == 1)a++;
    else if (x == 2)b++;
    else c++;
  }
  cout << fixed << setprecision(12) << solve(a, b, c, n);



}

