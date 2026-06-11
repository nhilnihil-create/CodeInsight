#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n;
  string s;
  cin >> n >> s;
  vint W(n);
  vint B(n);
  int count = 0;
  rep(i,n){
    if(s[i] == '#') count++;
    W[i] = count;
  }
  count = 0;
  for(int i = n-1;i >= 0;i--){
    if(s[i] == '.') count++;
    B[i] = count;
  }
  int ans = INF;
  rep(i,n-1){
    ans = min(ans,W[i]+B[i+1]);
  }
  ans = min(ans,B[0]);
  ans = min(ans,W[n-1]);
  cout << ans << endl;
}