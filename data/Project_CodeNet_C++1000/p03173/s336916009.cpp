#include<iostream>
using namespace std;

long long a[10000],dp[1000][1000];


main(){
	long long k,sum[10000];
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
		if(i==0)
			sum[i]=a[i];
		else
			sum[i]=a[i]+sum[i-1];
	}
	for(int i=0;i<k;i++){
		for(int j=i-1;j>=0;j--){
			dp[j][i]=10000000000000;
			for(int o=j;o<i;o++){
				long long s=sum[i];
				if(j>0)
	 				s-=sum[j-1];
	 			dp[j][i]=min(dp[j][i],dp[j][o]+dp[o+1][i]+s);
			}
		}
	}
	cout<<dp[0][k-1]<<endl;
}