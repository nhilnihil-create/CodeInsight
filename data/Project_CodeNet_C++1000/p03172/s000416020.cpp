#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e2+5 , M = 1e5+5 , MOD = 1e9+7;;

int n , k;
ll A[N] , sum[N] , bit[N][M] , dp[N][M];

void add(int x , int y , int val){
  for(int i = y ; i < M  ; i+=i&-i) bit[x][i] = (bit[x][i]+val)%MOD;
}

ll query(int x , int y){
  ll r = 0;
  for(int i = y ; i > 0 ; i-=i&-i) r = (r+bit[x][i])%MOD;
  return r;
}

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> n >> k;

  for(int i = 1 ; i <= n ; i++){cin >> A[i]; sum[i] = (sum[i-1]+A[i])%MOD;}

  for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;

  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= min(sum[i],(ll)k) ; j++){
      dp[i][j] = ((query(i-1,j)-query(i-1,max((ll)0,j-A[i]-1))+MOD)%MOD + (A[i] >= j))%MOD;
      //cout << query(i-1,j)-query(i-1,max((ll)0,j-A[i]-1)) << " " << (A[i] >= j) << "\n";
      //cout << i << " " << j << ": " << dp[i][j] << "\n";;
      add(i,j,dp[i][j]); 
    }

  cout << dp[n][k] << "\n";

}
