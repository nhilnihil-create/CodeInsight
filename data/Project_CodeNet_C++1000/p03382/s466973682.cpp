#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxn=1e5+10;
int n,a[maxn],x=-1;

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i)
		if(min(a[i],a[n]-a[i])>min(x,a[n]-x))
			x=a[i];
	cout<<a[n]<<' '<<x<<endl;
	return 0;
}