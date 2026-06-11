#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum=0,m=0;
	for(int i=0;i<n;i++){
		int z;
		cin>>z;
		sum+=z;
		m=max(m,z);
	}
	cout<<sum-m/2<<endl;
	
	return 0;
}