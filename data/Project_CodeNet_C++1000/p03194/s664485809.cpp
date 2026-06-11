#include<iostream>
#include<cmath>
using namespace std;
long long n,p,maxn=0,k,t;

int Judge(long long x,long long y){
	long long num=0;
	while(y%x==0){
		num++;
		y=y/x;
		if(num>=n) break;
	}
	return num;
}
int main(){
	
	cin>>n>>p;
	
	if(n==1) cout<<p<<endl;
	else if(n>=40) cout<<"1"<<endl;
	else{
		for(long long i=2;;i++){
			k=pow(i,n);
			if(k>=p){
				t=i; break;
			}
		}
		//cout<<t<<endl;
		for(long long i=2;i<=t;i++){
			long long x=Judge(i,p);
			if(x>=n) maxn=i;	
		}
		if(maxn==0) cout<<"1"<<endl;
		else cout<<maxn<<endl;
	}
	return 0;	
} 