
#include <bits/stdc++.h>
using namespace std;
     
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
     
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
const int inf = 1000000001;
const ll INF = 1e18;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main(){
  string s;
  cin >> s;
  int n = s.size(), i, j;
  vl sum(n + 1);
  for (i = 0; i < n; i++){
    sum[i + 1] = sum[i] ^ (1 << (s[i] - 'a'));
  }
  vl x(27);
  x[1] = 1;
  for(i = 1; i < 26; i++){
    x[i + 1] = 2 * x[i];
  }
  vi dp((1 << 26), inf);
  dp[0] = 0;
  for(i = 1; i <= n; i++){
    //cout << i << endl;
    int m = inf + 2;
    for(j = 0; j < 27; j++){
      //cout<<j<<": ";
      //cout<<dp[x[j] ^ sum[i]]<<endl;
      m = min(m, dp[x[j] ^ sum[i]]);
    }
    //cout << m + 1 << endl << endl;
    dp[sum[i]] = min(dp[sum[i]], m + 1);
  }
  if (dp[sum[n]])
    cout << dp[sum[n]] << endl;
  else
    cout << 1 << endl;
}
