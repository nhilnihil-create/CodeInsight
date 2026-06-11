#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		sum+=a[i];
	}
	int m=10005;
	for(int i=0;i<n;i++)
		m=min(abs(sum-a[i]*n),m);
	for(int i=0;i<n;i++){
		if(abs(sum-a[i]*n)==m){
			printf("%d",i);
			return 0;
		}
	} 
}