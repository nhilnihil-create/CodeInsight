#include<bits/stdc++.h>
using namespace std;
int  n,k,a[200001],x,sum=0,p;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;				
	}
	sort(a+1,a+1+n);
	p=1;
	while(a[p]==0)p++;
	for(int i=p;i<=n-k;i++)
		sum+=a[i];
	
	cout<<sum<<endl;
}