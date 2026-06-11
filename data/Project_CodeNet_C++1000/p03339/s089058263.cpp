#include<bits/stdc++.h>
#include<math.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  int dp[N]={};
  for (int i=1;i<N;i++){
    if (S.at(i)=='E') dp[0]++;
  }
  for (int i=1;i<N;i++){
    if (S.at(i)==S.at(i-1)){
      if (S.at(i)=='E') dp[i] = dp[i-1]-1;
      if (S.at(i)=='W') dp[i] = dp[i-1]+1;
    }
    else dp[i] = dp[i-1];
  }
  sort(dp, dp+N);

  cout << dp[0] << endl;

}
 