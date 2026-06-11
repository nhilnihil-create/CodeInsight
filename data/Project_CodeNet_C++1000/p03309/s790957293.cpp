#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long arr[n+1];
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++) arr[i]-=i;
	sort(arr+1,arr+n+1);
	int p1 = 1;
	int p2 = n;
	long long ret = 0;
	while(p1<p2){
		ret+=arr[p2]-arr[p1];
		p1++;
		p2--;
	}
	cout<<ret;
}