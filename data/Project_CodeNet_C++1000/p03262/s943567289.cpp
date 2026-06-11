#include<bits/stdc++.h>
using namespace std;
int LCD(int a,int b){
	if(a<b) swap(a,b);
	while(b){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	int n,x;
	cin>>n>>x;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	arr.push_back(x);
	sort(arr.begin(),arr.end());
	vector<int>diff;
	for(int i=1; i<arr.size(); i++) diff.push_back(arr[i]-arr[i-1]);
	int lcd = diff[0];
	for(int i=1; i<diff.size(); i++) lcd = LCD(lcd,diff[i]);
	cout<<lcd;
}