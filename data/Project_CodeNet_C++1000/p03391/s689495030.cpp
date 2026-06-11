#include <bits/stdc++.h>
using namespace std;

int main() {
	long n,j=0,k=0;
	cin>>n;
	long a[n],b[n],c[200010];
	for(long i=0;i<n;i++)cin>>a[i]>>b[i];
	for(long i=0;i<n;i++)k+=a[i];
	for(long i=0;i<200010;i++)c[i]=1000000001;
	for(long i=0;i<n;i++){
		if(a[i]>b[i]){
			c[j]=b[i];
			j++;
		}
	}
	sort(c,c +n);
	if(j>0){
	cout<<k-c[0]<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}