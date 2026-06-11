#include<bits/stdc++.h>
using namespace std;
const int N = 200100;

long long ret; 
long long n,a[N];
int main(){
    scanf("%lld",&n);
    for(int i=1; i<=n; i++){
    	scanf("%lld",&a[i]);
	}
    long long j=0,sum=0,xorsum=0;
	for(int i=1; i<=n; i++){
    	while(j+1<=n&&sum+a[j+1]==(xorsum^a[j+1])){
    		sum=sum+a[j+1];
		    xorsum=xorsum^a[j+1]; 
			j++;
		}
		ret+=j-i+1;
		sum-=a[i];
		xorsum^=a[i];
	}
	printf("%lld",ret); 
	return 0;
} 