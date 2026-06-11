#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
inline int read(){
	int sum=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		sum=(sum<<1)+(sum<<3)+(c^48);
		c=getchar();
	}
	return sum;
}
bitset<4000005> f;
int n;
int main(){
	n=read();
	f[0]=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		int a=read();
		sum+=a;
		f|=f<<a;
	}
	for(int i=(sum+1)/2;i<=sum;i++)
	  if(f[i]){
	  	  printf("%d\n",i);
	  	  return 0;
	  }
	return 0;
}