#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	vector<int>sorted(arr.begin(),arr.end());
	sort(sorted.begin(),sorted.end());
	int median = sorted[n/2];
	for(int i=0; i<n; i++){
		if(arr[i]>=median) cout<<sorted[n/2-1]<<'\n';
		else cout<<median<<'\n';
	}
}