#include<bits/stdc++.h>
using namespace std;
int a[2][101];
int sum1[105],sum2[105];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<2;i++) for(int j=0;j<n;j++) cin>>a[i][j];
	for(int i=1;i<n;i++) a[0][i]=a[0][i-1]+a[0][i];
	for(int i=n-2;i>=0;i--) a[1][i]=a[1][i+1]+a[1][i];
	int ans=-1;
	for(int i=0;i<n;i++) ans=max(ans,a[0][i]+a[1][i]);
	cout<<ans; 
	return 0;
}
