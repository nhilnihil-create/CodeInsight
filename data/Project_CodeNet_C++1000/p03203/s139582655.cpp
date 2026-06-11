#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12


struct ten_t {
	int x;
	int y;
} ;

int compare_ten(const void *a, const void *b) {
  struct ten_t *A = (struct ten_t *)a;
  struct ten_t *B = (struct ten_t *)b;
  return A->x - B->x;
}

int main(void)
{
	//変数の宣言
	int h,w,n;
	static struct ten_t ten[200010];
	
	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;

	//データの読み込み
	scanf("%d %d %d",&h,&w,&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&ten[i].x,&ten[i].y);
	}
	
	
//	printf("nは%dです\n", n);
//	printf("データの読み込み終了\n");
	//実際の処理
	qsort(ten, n, sizeof(struct ten_t), compare_ten);
	
	j=0;
	temp=1;
	for(i=1;i<=h;i++){
		while(ten[j].x==i&&j<n){
			if(ten[j].y<temp){
				printf("%d",i-1);
				return 0;
			}else if(ten[j].y==temp){
				flag=1;
			}
			j++;
		}
		if(flag==1){
			flag=0;
		}else{
			temp++;
		}
	}
	
//	printf("計算部分終了\n");
	//出力
	printf("%d",h);
	
	
//	printf("結果の出力終了\n");
	
	return 0;
	
}

