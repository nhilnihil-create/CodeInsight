#include<cstdio>
#include<cstdlib>
int main(void){
	int N,A,B;
	scanf("%d%d%d",&N,&A,&B);
	if(A + B - 1> N || (long)A*(long)B < (long)N){
		printf("%d\n",-1);
		fflush(stdout);
		return 0;
	}
	if(A > B){
		int i = 0,j=0;    
	    for(i=N - A + 1;i<=N;i++){
	        printf("%d ",i);
	    }
	    j = N-A+1;
	    int k;
	    if(B > 1){
	    	for(k=0; k < (N-A)%(B-1);k++){ 
				for(i=j - (N-A)/(B-1)-1;i< j;i++){
					printf("%d ",i);
				}
				j = j - (N-A)/(B-1)-1;
			}
			for(k=0; k < B-1 - (N-A)%(B-1);k++){ 
				for(i=j  - (N-A)/(B-1);i< j;i++){
					printf("%d ",i);
				}
				j = j - (N-A)/(B-1);
			}
			
		}
	}else{
		int i = 0,j=0;    
	    for(i=B;i>0;i--){
	        printf("%d ",i);
	    }
	    j = B;
	    int k;
	    if(A > 1){
			for(k=0; k < (N-B)%(A-1);k++){  
				for(i=j + (N-B)/(A-1) + 1;i > j;i--){
					printf("%d ",i);
				}
				j = j + (N-B)/(A-1) + 1;	
			}
			for(k=0; k < A-1 - (N-B)%(A-1);k++){  
				for(i=j + (N-B)/(A-1);i > j;i--){
					printf("%d ",i);
				}
				j = j + (N-B)/(A-1);	
			}

		}
	}
	
	printf("\n");
	fflush(stdout);
	return 0;
}