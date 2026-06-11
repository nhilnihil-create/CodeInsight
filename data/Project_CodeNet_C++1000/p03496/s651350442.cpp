#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,mn,mx,a[101],opmx,opmn;
int main(){
	mn=1e9;mx=-1e9;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
      scanf("%d",&a[i]);
      if(a[i]<mn)mn=a[i],opmn=i;
      if(a[i]>mx)mx=a[i],opmx=i;
}
    printf("%d\n",n*2-2);
   if(abs(mx)>=abs(mn)){
   	printf("%d %d\n",opmx,n);
   	printf("%d %d\n",opmx,n);
   	for(i=2;i<n;i++){
   		printf("%d %d\n",n,i);
   		printf("%d %d\n",n,n);
	   }
   }
    else{
    	printf("%d %d\n",opmn,1);
    	printf("%d %d\n",opmn,1);
    	for(i=n-1;i>1;i--){
    		printf("%d %d\n",1,i);
    		printf("%d %d\n",1,1);
		}
	}
}