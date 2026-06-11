#include<bits/stdc++.h>
using namespace std;
long n,r,l=-1,m,c,s,i,N,a[1<<17];
main(){
	for(cin>>n;cin>>m;r=r<m?m:r)a[i++]=m;
	for(;r-l>1;(c>n*(n+1)/4?r:l)=m){
		int b[2*n]={};
		m=l+r>>1;
		b[s=n]=1;
		for(N=c=i=0;i<n;b[s]++,c+=N)N+=a[i++]>m?-b[++s]:b[s--];
	}
	cout<<r;
}