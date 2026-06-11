#include<bits/stdc++.h>
using namespace std;
int GCD(int a,int b){
	if(a<b) swap(a,b);
	while(b){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	int gcd = arr[0];
	for(int i=1; i<arr.size(); i++) gcd = GCD(gcd,arr[i]);
	cout<<gcd;
}