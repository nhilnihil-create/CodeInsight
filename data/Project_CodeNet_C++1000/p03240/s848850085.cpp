#include<cstdio>
#include<algorithm>
using namespace std;
int a[105],b[105],c[105];
int main(){
	int n,ans1,ans2,k,q,u;
	scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=0;i<=100;i++){
    	for(int j=0;j<=100;j++){
    		for(q=0;q<n;q++){
    			if(c[q]!=0){
    				ans1=abs(i-a[q])+abs(j-b[q])+c[q];
    				break;
				}
			}
			if(q==n){
				for(u=0;u<n;u++){
					if(i==a[u]&&j==b[u]) break;
				}
				if(u==n) printf("%d %d %d",i,j,1);
				return 0;
			}
    		for(k=0;k<n;k++){
				ans2=abs(i-a[k])+abs(j-b[k])+c[k];
    			if(c[k]!=0){
    				if(ans1!=ans2) break;
    				ans1=ans2;
				}
    			else{
    				if(ans1>ans2) break;
				}
			}
			if(k==n){
				printf("%d %d %d",i,j,ans1);
				return 0;
			}
		}
	}
}