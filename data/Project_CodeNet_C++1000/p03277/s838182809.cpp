#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

int n,l,r,a[200001],s[200001],c[400001];

int lowbit(int x){
	return x&(-x);
}

long long query(int x){
	int i;
	long long sum=0;
	for(i=x;i>=1;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

void add(int x){
	for(int i=x;i<=2*(n+1);i+=lowbit(i))
		c[i]++;
}

bool check(int x){
	int i;
	long long sum=0;
	for(i=1;i<=2*(n+1);i++)
		c[i]=0;
	for(i=1;i<=n;i++)
		s[i]=s[i-1]+(a[i]>=x?1:-1);
	for(i=0;i<=n;i++){
		sum+=query(s[i]+n+1);
		add(s[i]+n+1);
	}
	return sum>=1ll*n*(n+1)/4;
}

int main(){
	int mid,i;
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> a[i];
		r=max(r,a[i]);
	}
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout << r;
	return 0;
}