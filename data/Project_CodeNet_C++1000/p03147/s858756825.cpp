#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+2]={0};
	for(int i=1; i<=n; i++) cin>>arr[i];
	int localmax = arr[1];
	int localmin = arr[0];
	long long ret = 0;
	for(int i=1; i<=n+1; i++){
		if(arr[i-1]==arr[i]) continue;
		else if(arr[i]>arr[i-1]) localmax = arr[i];
		else{
			ret+=(localmax-localmin);
			localmax = arr[i];
			localmin = arr[i];
		}
	}
	cout<<ret;
}