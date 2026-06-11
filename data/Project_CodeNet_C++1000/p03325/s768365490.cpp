#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> arr;
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		arr.push_back(a);
	}long long ans=0;
	int i=0;
	while(i<n){
		if(arr[i]%2==0){
			ans++;
			arr[i]/=2;
		}else
			i++;
	}
	cout<<ans;
	return 0;
}