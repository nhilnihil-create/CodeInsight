#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std; 

int n,t,k;
char c[1000005];
ll ans=0;

int main(void){
	scanf("%d",&n);
	scanf("%s",c);
	int ss=0; 
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		ans=0ll;
		ll front=0ll,m=0ll,d=0ll;
		for(int i=0;i<n;i++){
			if(c[i]=='C')ans+=front;
			if(c[i]=='D')d++;
			if(c[i]=='M'){
				m++;
				front+=d;
			}
			if(k-1<=i){
				if(c[i-k+1]=='M')m--;
				if(c[i-k+1]=='D'){
					d--;
					front-=m;
				} 
			}
		} 
		printf("%lld\n",ans);
	}
}