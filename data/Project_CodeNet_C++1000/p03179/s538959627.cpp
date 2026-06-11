#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;
const int N = 3e3+5;
const ll MOD = 1e9+7;

int n;
ll dp[N][N];
string s;

// '>': dp[i][j]=dp[i-1][j] + ... + dp[i-1][i]
// '<': dp[i][j]=dp[i-1][j+1] + ... + dp[i-1][i] 

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cin >> n >> s;

  dp[1][1]=(s[0]=='>'); 
  dp[1][2]=1;

  for(int i=2; i<n; i++){
    for(int j=1; j<=i+1; j++){
      if(s[i-1]=='>') dp[i][j]=(dp[i-1][i]-dp[i-1][j-1] + MOD)%MOD;
      else dp[i][j]=dp[i-1][j-1];
      dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD; 
    }
  }

  cout << dp[n-1][n] << endl;
}