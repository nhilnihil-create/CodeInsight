#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int a[200005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int r=0;
	long long ans=0,sum=a[0];
	for(int l=0;l<n;l++){
		if(l>0)sum-=a[l-1];
		while(r<n-1 && sum+a[r+1]==(sum^a[r+1])){
			r++;
			sum+=a[r];
		}
		ans+=r-l+1;
	}
	cout<<ans<<endl;
	return 0;
}