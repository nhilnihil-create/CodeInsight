#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

double dp[301][301][301] = {};
int n;

double dfs(int a, int b, int c){
  if(a == 0 && b == 0 && c == 0) return 0;
  if(dp[a][b][c] != 0) return dp[a][b][c];
  double x = 0, y = 0, z = 0;
  if(a > 0){
    x = dfs(a-1,b,c);
  }
  if(b > 0){
    y = dfs(a+1,b-1,c);
  }
  if(c > 0){
    z = dfs(a,b+1,c-1);
  }
  return dp[a][b][c] = (n + x*(double)a + y*(double)b + z*(double)c)/(double)(a+b+c);
}

int main(){
  fix20;

  cin >> n;
  vi a(n);
  int r[3] = {};
  long sum = 0;
  rep(i,n){
    int a;
    cin >> a;
    sum += a;
    r[a-1]++;
  }
  cout << dfs(r[0], r[1], r[2]) << endl;
}