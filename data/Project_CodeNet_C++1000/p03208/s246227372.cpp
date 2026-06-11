#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long k;
	cin >> k;
	vector<long long> arr;
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		arr.push_back(a);
	}sort(arr.begin(),arr.end());
	long long ans=INT_MAX;
	for(long long i=0;i<n-k+1;i++){
		long long na=arr[i+k-1]-arr[i];
		if(na<ans){
			ans=na;
		}
	}
	cout<<ans;
	return 0;
}