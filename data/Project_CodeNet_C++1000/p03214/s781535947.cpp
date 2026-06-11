#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100],ave=0,dist=10000;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],ave+=a[i],a[i]*=n;
	for(int i=0;i<n;i++)
		dist=min(dist,abs(ave-a[i]));
	for(int i=0;i<n;i++)
		if(abs(ave-a[i])==dist)
			cout<<i<<endl,exit(0);
}
