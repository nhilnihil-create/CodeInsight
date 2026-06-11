#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,t,A;
	cin>>n>>t>>A;
	double a[n];
	double mx=1e9,ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		double x=t-a[i]*0.006;
		if(abs(A-x)<mx){
			mx=abs(A-x);
			ans=i+1;
		}
	}
	cout<<ans;

}