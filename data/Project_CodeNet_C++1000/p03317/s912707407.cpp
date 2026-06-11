#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>arr[i];
	int curr=n;
	int ret = 0;
	while(curr>1){
		for(int i=0; i<k; i++) curr--;
		curr++;
		ret++;
	}
	cout<<ret;
}