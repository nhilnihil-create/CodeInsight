#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <cstring>

#define ll long long
using namespace std; 

void solve(){
  int n ,k;
  cin >> n>>k ; 
  vector<int> a(n); 
  for(int i=0 ; i<n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end()); 
  bool dp[k+1]; 
  int curr = 0; 
  dp[0] = false; 
  for(int i=1; i<=k; i++){
    dp[i] = false; 
    for(int j=0; j<n; j++){
      if(i-a[j]<0){
        break; 
      }
      dp[i] |= !(dp[i-a[j]]);  
    }
  }
  std::cout <<  (dp[k]? "First\n" : "Second\n");
}

int main(){
  int t=1; 
  // cin>>t; 
  while(t--){
    solve(); 
  }
 return 0;
}