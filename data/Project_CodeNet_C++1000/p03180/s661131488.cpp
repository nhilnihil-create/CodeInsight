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
const int N = 1<<16+5;
ll a[20][20], sum[N], dp[N];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> a[i][j];

  dp[0]=0;
  for(int p=1; p<(1<<n); p++){
    for(int i=0; i<n; i++){
      if(!(p&(1<<i))) continue;
      for(int j=i+1; j<n; j++){
        if(!(p&(1<<j))) continue;
        sum[p]+=a[i][j];
      }
    }
    dp[p]=-linf;
  }

  for(int p=0; p<(1<<n); p++){
    vector <ll> cur;
    for(int  i=0; i<n; i++) if(p&(1<<i)) cur.pb(i);
    for(int k=0; k<(1<<cur.size()); k++){
      int sp=0;
      for(int i=0; i<n; i++) if(k&(1<<i)) sp^=(1<<cur[i]);
      dp[p]=max(dp[p], sum[sp]+dp[p-sp]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
}