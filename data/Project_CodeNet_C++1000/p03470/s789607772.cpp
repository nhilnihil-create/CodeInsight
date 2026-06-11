#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<int> arr;
	vector<int>::iterator ip;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}sort(arr.begin(), arr.end());
	ip = unique(arr.begin(), arr.begin() + n);
	int ans=distance(arr.begin(), ip);
	cout<<ans;
	return 0;
}