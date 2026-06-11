#include<bits/stdc++.h>
using namespace std;
bitset<4919810> s;  
int n,sum;
int main(){
	scanf("%d",&n);s[0]=1;
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),sum+=x,s|=(s<<x);if(sum%2==1) sum++;
	for(int i=sum/2;i<=sum;i++)
		if(s.test(i)) {printf("%d",i);exit(0);}
}