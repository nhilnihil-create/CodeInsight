#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n+2);
	for(int i=1;i<=n;i++)
	cin>>a[i];
	map<int,int> m;
	int s=0;
	for(int i=0;i<=n;i++){
		m[i+1]=fabs(a[i]-a[i+1])+fabs(a[i+1]-a[i+2]);
		s+=fabs(a[i]-a[i+1]);
	}
	for(int i=1;i<=n;i++){
		int b=s-m[i]+fabs(a[i-1]-a[i+1]);
		cout<<b<<endl;
	}
}