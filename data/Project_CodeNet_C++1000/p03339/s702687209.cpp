#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; string s;
  cin >> n >> s;
  vector<int> e(n+1);
  rep(i,0,n) {
    e[i+1] += e[i];
    if (s[i] == 'E') e[i+1]++;
  }
  int ans = 10000000;
  rep(i,0,n) {
    int k = i - e[i] + e[n] - e[i+1];
    ans = min(ans,k);
  }
  cout << ans << endl;
  return 0;
}