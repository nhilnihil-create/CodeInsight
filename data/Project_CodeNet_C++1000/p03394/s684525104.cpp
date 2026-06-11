#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n==3){
		puts("2 5 63");
		return 0;
	}
	if(n==4){
		puts("2 5 20 63");
		return 0;
	}
	for(register int i=2;i<n;i+=2)
		if((n-i)<=15000&&i<=5000&&(n-i)%3!=1){
        	for(int j=2,c=1;j<=30000&&c+i<=n;j+=2,c++) printf("%d ",j);
        	for(int j=3,c=1;j<=30000&&c<=i;j+=3) if(j&1) printf("%d ",j),c++;
        	break;
    	}
	return 0;
}