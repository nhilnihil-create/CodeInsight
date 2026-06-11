#include "bits/stdc++.h"
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define show(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
#else
#define show(...) 42
#endif


#define f first
#define s second
#define endl "\n"
#define pb push_back
#define  oo 0x3f3f3f3f
#define limit 1000000007
#define int long long int
#define mod(x,m) ((x%m+m)%m)
#define ll long long
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define fastio std::ios::sync_with_stdio(false)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define input_from_file  freopen("input.txt", "r", stdin);

signed main(){
  //input_from_file;
  int n; cin>>n;
  int dp[n+1][n+1];
  memset(dp,0,sizeof dp);
  // dp[i][j] represents upto i and the last no is j;
  for(int i=1;i<=n;i++) dp[1][i] = 1;
  string str; cin>>str;
  for(int i=2;i<=n;i++){
   for(int j=1;j<=i;j++)
    if(str[i-2] == '>') dp[i][j] = (dp[i-1][n]%limit-dp[i-1][j-1]%limit+limit)%limit;
    else dp[i][j] = dp[i-1][j-1];
   for(int j=1;j<=n;j++) dp[i][j] = (dp[i][j]+dp[i][j-1])%limit;
  }
  cout<<dp[n][n]<<endl;
}
