#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n+2]={0};
	for(int i=1; i<=n; i++) cin>>arr[i];
	int cost = 0;
	for(int i=0; i<=n; i++) cost+=abs(arr[i]-arr[i+1]);
	for(int i=1; i<=n; i++){
		int curr = cost-abs(arr[i]-arr[i-1])-abs(arr[i]-arr[i+1]);
		curr+=abs(arr[i-1]-arr[i+1]);
		cout<<curr<<'\n';
	}
}