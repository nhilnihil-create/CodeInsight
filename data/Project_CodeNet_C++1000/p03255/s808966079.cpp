#include<iostream>
using namespace std;
typedef long long int LL;
const LL MAX=(LL)1<<60;
LL x[200005];
LL t[200005];
int main(){
	LL n,m;
	LL a,b,c;
	LL i,j,k;
	LL s=(LL)1<<60;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>x[i];
		if(i==0)t[i]=x[i];
		else t[i]=t[i-1]+x[i];
	}
	for(i=1;i<=n;i++){
		a=m*(i+n);
		for(j=n-1,k=0;j>=0;j-=i,k++){
			if(k==0)a+=t[j]*(LL)5;
			else if(k>1)a+=t[j]*(LL)2;
			if(a>MAX)break;
		}
		if(s>a)s=a;
	}
	cout<<s<<endl;
	return 0;
}
		
