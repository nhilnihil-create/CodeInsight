#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

#define INF 1 << 29
#define REP(i,n) for(ll i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(ll i=(k);i<(int)(n);i++)



vector<bool> gen_sosuu(vector<bool> sosuu){
  int size = sosuu.size();
  REP(i,size){
    sosuu[i] = true;
  }
  sosuu[0] = false;
  sosuu[1] = false;
  sosuu[2] = true;
  FOR(i,2,sqrt(size)+1){
    if(sosuu[i] == false) continue;
    for(int j = 2; i*j<size;j++){
      sosuu[i*j] =false;
    }
  }
  return sosuu;
}


ll f[100000];
ll g[100000];
ll x[100000];
int v[100000];
ll c;

int n;
ll ma;
int main(){
  cin >> n>>c;
  ll sum = 0;
  REP(i,n){
    cin >> x[i] >> v[i];
    sum += v[i];
    f[i] = sum - x[i];
    ma = max(ma,f[i]);
    g[i] = max(g[max(i-1,0ll)],f[i]-x[i]);
    //cout << g[i] << " " << f[i] << " " << ma<< endl;
  }
  sum = 0;
  for(int i = n-1;i>0;i--){
    sum += v[i];
    ma = max(ma,sum+g[i-1]-(c-x[i]));
    //cout << g[i-1] <<" " << ma << endl;
  }
  sum = 0;
  g[0] = 0;
  for(int i = n-1;i>=0;i--){
    sum += v[i];
    f[i] = sum - (c-x[i]);
    ma = max(ma,f[i]);
    g[i] = max(g[(i+1)%n],f[i]-(c-x[i]));
  }
  sum = 0;
  REP(i,n-1){
    sum += v[i];
    ma = max(ma,sum+g[i+1]-x[i]);
  }
  cout << ma << endl;
}

/*
ll dp[100001][2];
int x[100001];
int v[100001];
ll c;
dp[i]=iを通ったときの最大値
dp[i] = max(dp[i],dp[k]+x[i]-abs(v[i]-v[k]))
      = max(dp[i],dp[i-1]-abs(v[i]-v[i-1]),dp[i+1]-abs(v[i]-v[i+1]))
ll ma = 0;

int inde = 0;
int n;
int main (){
  cin >> n >> c;
  FOR(i,1,n+1){
    cin >> x[i]>> v[i];
    dp[i][0] = dp[i-1][0] + v[i] - abs(x[i]-x[i-1]);
    cout << dp[i][0] << endl;
    if(dp[0][0] < dp[i][0]-x[i]){
      dp[0][0] = dp[i][0]-x[i];
      inde = i;
    }
  }
  x[n] = c;
  dp[0][1] = dp[0][0];
  cout << dp[0][1] << "aaaa"<<endl;
  for(int i = n;i>inde;i--){
    dp[i][1] = dp[(i+1)%(n+1)][1] + v[i] - abs(x[i]-x[(i+1)%(n+1)]);
    cout << dp[i][1] << endl;
  }
  REP(i,n+1){
    ma = max(ma,dp[i][0]);
    ma = max(ma,dp[i][1]);
  }
  cout << ma << endl;
}
*/
