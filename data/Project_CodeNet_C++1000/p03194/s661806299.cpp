#include<bits/stdc++.h>

using namespace std;

int prime(long long n){
	for(long long i=2;i<=sqrt(n);i++){
    	if(n%i==0){
    	    return 0;
    	}
	}
	return 1;
}
	
int main()
{
	long long n,p;
	cin>>n>>p;
	if(n==1){
		cout<<p<<endl;
		return 0;
	}
		long long maxn= 1;
		double f=pow(p,1.0/n);
		for(long long i=f+1;i>=2;i--){
		long long sum=1;
		for(long long j=0;j<n;j++){
			sum*=i;
			if(sum>p)
				break;
			}
		if(p%sum==0){
			maxn=i;
			break;
		}
	}
	cout<<maxn<<endl;
}
