#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100000];
long long b[100000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<n;i++)	cin>>b[i];
	long long k=0;
	for(int i=0;i<n;i++)	k+=b[i]-a[i];
	long long two=0;
	for(int i=0;i<n;i++)
	{
		long long d=b[i]-a[i];
		if(d>0)	two+=(d+1)/2;
	}
	if(two>k) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}