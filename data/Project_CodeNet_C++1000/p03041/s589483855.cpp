#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) v.begin(), v.end()
#define ll long long
ll INF = 1e9;
ll mod = 1e9+7;

ll dp[10001];
int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;
  if(s[k-1]=='A') s[k-1]='a';
  else if(s[k-1]=='B') s[k-1]='b';
  else s[k-1]='c';
  cout << s << endl;
}
