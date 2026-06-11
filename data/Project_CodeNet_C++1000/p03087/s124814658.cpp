#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int>dp(n+1,0);
  for(int i=0;i<n-1;i++){
    if(s.at(i)=='A'&&s.at(i+1)=='C'){
      dp[i+1]=1;
    }
    dp[i+1]+=dp[i];
  }
  for(int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    r--;
    l--;
    cout << (dp[r]-dp[l]) << endl;
  }
}