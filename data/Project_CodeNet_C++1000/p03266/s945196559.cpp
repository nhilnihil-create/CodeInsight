#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0; i<n; i++) arr[i]=i+1;
	for(int i=0; i<n; i++) arr[i]%=k;
	if(k%2){
		long long zero = 0;
		for(int i=0; i<n; i++) if(arr[i]==0) zero++;
		long long ret = pow(zero,3);
		cout<<ret;
	}
	else{
		long long zero = 0;
		long long half = 0;
		for(int i=0; i<n; i++){
			if(arr[i]==0) zero++;
			else if(arr[i]==k/2) half++;
		}
		long long ret = pow(zero,3);
		ret+=pow(half,3);
		cout<<ret;
	}
}