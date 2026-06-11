#include <bits/stdc++.h>
using namespace std;
extern const int N = 100000;
int dp[N +1];
int compute(int arr[], int n, int i){
  if(i == n-1){
  	return 0;
  }
  
  if(dp[i] != -1){
  	return dp[i];
  }
  
  int c1 = abs(arr[i] - arr[i+1]) + compute(arr, n, i+1);
  int c2 = INT_MAX;
  if(i+2 <=n-1){
    c2 = abs (arr[i]-arr[i+2]) + compute(arr,n, i+2);
  }
   

  return dp[i] = min(c1, c2);
}


int main() {
 	
  int n;
  cin >> n;
  int arr[n];
  
  for(int i = 0; i < n; i++){
  	cin >> arr[i];
  }
  memset(dp, -1, sizeof dp);
  cout<< compute(arr, n, 0);
  
  return 0;
}