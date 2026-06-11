#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	arr.push_back(1000000001);
	sort(arr.begin(),arr.end());
	int ret = 0;
	int counter = 0;
	for(int i=1; i<arr.size(); i++){
		if(arr[i-1]==arr[i]) counter++;
		else{
			counter++;
			if(counter<arr[i-1]) ret+=counter;
			else ret+=(counter-arr[i-1]);
			counter = 0;
		}
	}
	cout<<ret;
}