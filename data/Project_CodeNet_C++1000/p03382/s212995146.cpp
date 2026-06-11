#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[100001],maxn,m1=(int)2.1e9,m2;

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;++i){
		if(a[i]==maxn)continue;
		int dst=abs(maxn-a[i]*2);
		if (m1>dst){m1=dst;m2=a[i];}
	}
	cout<<maxn<<" "<<m2<<"\n";
	return 0;
}