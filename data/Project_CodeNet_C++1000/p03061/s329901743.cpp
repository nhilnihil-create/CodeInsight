#include <iostream>
#include <cstdio>
#include <cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+7;
int a[maxn],b[maxn],c[maxn];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=gcd(b[i-1],a[i]);
	}
	c[n]=a[n];
	for(int i=n-1;i>=1;i--){
	c[i]=gcd(c[i+1],a[i]);
	}
	int g=0;
	for(int i=2;i<=n;i++){
		g=max(gcd(b[i-1],c[i+1]),g);
	}
	g=max(g,max(c[2],b[n-1]));
	cout<<g;
}