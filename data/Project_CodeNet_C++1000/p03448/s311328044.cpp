#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,ans,x,i,l,j;
	scanf("%d%d%d%d",&a,&b,&c,&x);
	for(int i=0;i<=a;i++){
		for(int l=0;l<=b;l++){
			for(int j=0;j<=c;j++){
				if(500*i+100*l+50*j==x)
    			ans++;	
    			if(500*i+100*l+50*j>x)
    			break;
			}
			
		}
			
	}

    printf("%d\n",ans);
    return 0;
}