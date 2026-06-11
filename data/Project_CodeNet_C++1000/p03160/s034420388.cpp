#include<iostream>
#include<cstring>
using namespace std;

int dp[100001];

int solve(int* arr, int i, int n) {
	if(i==n) return 0;
  
    if(dp[i] != -1) return dp[i];

  	int op1 =10e8;
  	int op2 =10e8;
  
  	if(i+1 <= n) op1 = abs(arr[i] - arr[i+1]) + solve(arr, i+1, n);
	
  	if(i+2 <= n) op2 = abs(arr[i] - arr[i+2]) + solve(arr, i+2, n);
  
  	return dp[i] = min(op1, op2);

}
 
int main() {
  	int n;
  	cin>>n;
  	
  	int* arr = new int[n];
  	for(int i=0; i<n; i++) cin>>arr[i];
    memset(dp, -1, sizeof(dp));
  	cout<<solve(arr, 0, n-1);
  	
	return 0;
}