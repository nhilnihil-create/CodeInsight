#include<iostream>
#include<cstdio>
#include<algorithm>
#define reg register
using namespace std;
const int MN=2000;
int a[MN],available[MN],index=0,ans=2147483647;
int main(){
	int N,K,Q;
	scanf("%d%d%d",&N,&K,&Q);
	for(reg int i=1;i<=N;++i){
		scanf("%d",a+i);
	}
	//X-Y
	for(reg int i=1;i<=N;++i){
		index=0;
		int Y=a[i],begin=1,end=0;
//		printf("MIN=%d\n",Y);
		for(reg int j=1;j<=N+1;++j){
			if(a[j]<Y){
				end=j-1;
				int length=end-begin+1;
//				printf("  [%d,%d] len=%d\n",begin,end,length);
				if(length>=K){
					for(reg int k=begin;k<=end;++k){
						available[++index]=a[k];
//						printf("   index=%d\n",index);
					}
					sort(available+index-length+1,available+index+1);
//					    printf("  [after sort]available:");
//						for(reg int i=1;i<=index;++i){
//							printf("%09d ",available[i]);
//						}
//						printf("\n");
					index=index-K+1;
//					printf("    index=%d\n",index);
				}
				begin=j+1;
			}
		}
		if(index>=1) sort(available+1,available+index+1);
//			printf("  available:");
//			for(reg int i=1;i<=index;++i){
//				printf("%d ",available[i]);
//			}
//			printf("\n");
		if(index>=Q) ans=min(ans,available[Q]-available[1]);
	}
	printf("%d",ans);
	return 0;
}