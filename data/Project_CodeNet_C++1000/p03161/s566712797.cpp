#include<iostream>
#include<cstring>
using namespace std;

int dp[100001];

int solve(int* arr, int i, int n, int k) {
	if(i==n) return 0;
  
    if(dp[i] != -1) return dp[i];

  	int op1 =10e8;
  	//int op2 =10e8;
  
  	for(int j=1; j<=k; j++) {
          if(i+j<=n) {
              int val = abs(arr[i+j] - arr[i]) + solve(arr, i+j, n, k);
              op1 = min(op1, val);
          }
      }
  
  	return dp[i] = op1;

}
 
int main() {
  	int n;
  	cin>>n;
  	
    int k;
    cin>>k;

  	int* arr = new int[n];
  	for(int i=0; i<n; i++) cin>>arr[i];
    memset(dp, -1, sizeof(dp));
  	cout<<solve(arr, 0, n-1, k);
  	
	return 0;
}