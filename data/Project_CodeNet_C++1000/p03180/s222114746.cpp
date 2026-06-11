#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  int N; cin >> N;
  vector<vector<ll>> a(N,vector<ll>(N));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> a[i][j];
    }
  }

  
  vector<ll> gr((1<<N),0);
  for(int i=1;i<N;i++){
    for(int j=0;j<(1<<i);j++){
      for(int k=0;k<i;k++){
        if((j>>k)&1) gr[(1<<i)+j]+=a[i][k];
      }
      gr[(1<<i)+j]+=gr[j];
      //cout << (1<<i)+j << " " << gr[(1<<i)+j] << endl;
    }
  }

  vector<ll> dp((1<<N),-4e11);
  dp[0]=0;
  for(int i=0;i<(1<<N);i++){
    for (int j = ((~i)&((1<<N)-1)); 0<=j; j--){
      j&=((~i)&((1<<N)-1));
      dp[i|j]=max(dp[i|j],dp[i]+gr[j]);
    }
  }
  
  cout << dp[(1<<N)-1] << endl;
  
  return 0;
}
