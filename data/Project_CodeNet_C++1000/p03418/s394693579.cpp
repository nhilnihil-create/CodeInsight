#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,k;
	cin>>n>>k;
	if(k==0){
		cout<<n*n;
		return 0;
	}
	long long ret = 0;
	for(int i=k+1; i<=n; i++){
		int curr = 0;
		int b = i;
		int cycle = b-k;
		curr+=(n/b)*cycle;
		int left = n%b;
		if(left>=k && left) curr+=left-k+1;
		ret+=curr;
	}
	cout<<ret;
}