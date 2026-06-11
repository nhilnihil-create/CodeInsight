#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	long long maxn=1;
	if(n==1){
		cout<<m<<endl;
		return 0;
	}
	double ff=m,fff=n;
	double f=pow(ff,1.0/fff);
	
	//cout<<f<<endl;
	for(long long i=f+1;i>=2;i--){
		long long sum=1;
		for(long long j=0;j<n;j++){
			sum*=i;
			if(sum>m)
				break;
			}
		if(m%sum==0){
			maxn=i;
			break;
		}
	}
	cout<<maxn<<endl;
}