#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int ctoi(char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  
  string A[n];
  int ans = 0;
  
  rep(i,n){
    string k = to_string(i+1);
    A[i] = k;
    
    int sum = 0;
    
    rep(j, A[i].size()){
      sum += ctoi(A[i][j]);
    }
    
    if(sum>=a && sum<=b){
      ans += (i + 1);
    }
  }
  
  cout << ans << endl;
  return 0;
}
