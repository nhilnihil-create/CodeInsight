#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mxn 100005
#define mp make_pair
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
int n;
int dp[mxn];
int rec(int arr[], int i){
	if(i==n-1) return 0;
	if(dp[i] != -1) return dp[i]; 
	if(i+2 < n)
		dp[i] = min(rec(arr,i+1)+abs(arr[i+1] - arr[i]), rec(arr,i+2)+ abs(arr[i+2] - arr[i]));
	else if(i+1 < n)
		dp[i] = rec(arr,i+1) + abs(arr[i+1] - arr[i]);
	return dp[i];
}
int main(){
	 cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<=n; i++){
		dp[i] = -1;
	}
	cout<<rec(arr,0);
}