#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long ans1=0,ans2=0,r=0;
	long long cnt=0;
	for(int l=1;l<=n;l++){
		while(((ans1+a[r+1])==(ans2^a[r+1]))&&r<n) ans1+=a[++r],ans2^=a[r];
		cnt+=(r-l+1);
		ans1-=a[l];
		ans2^=a[l];
	}
	cout << cnt << endl;
	return 0;
}