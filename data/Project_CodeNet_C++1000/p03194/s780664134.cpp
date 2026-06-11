#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
int main(void){
 
	long long int n,p;
	long long int cur[60000] = {};
	int count[60000] = {};
	int check[60000] = {};
	int end_flag = 0;
	int index = 0;
	int i,j;
 
	long long int result;
 
	scanf("%lld %lld",&n,&p);

 	if(n == 1){
		result = p;
	}else{


 
	//素因数分解を順番にしていって、
	//N個以上ある素因数の積を返す。
 
	//2の素因数分解
	cur[index] = 2;
	while(p % cur[index] == 0 && p > 1){
		count[index]++;
		p /= cur[index];
	}
	//N個以上あったらフラグを立てる
	if(count[index] >= n){		check[index] = count[index]/n;	}
 
 
	//次の因数セット
	index++;
	cur[index] = 3;
 
	while(p > 1 && p >= cur[index] * cur[index]){
		//cur[index]の素因数分解
		while(p % cur[index] == 0 && p > 1){
			count[index]++;
			p /= cur[index];
//			printf("p=%lld(%lld)\n",p,cur[index]);
		}
		//N個以上あったらフラグを立てる
		if(count[index] >= n){		check[index] = count[index]/n;	}
 
		index++;
		cur[index] = cur[index-1] + 2;
		do{
			end_flag = 1;
			for(i=0;i<index;i++){
				if(cur[index] % cur[i] == 0){
					end_flag = 0;
					cur[index] += 2;
					break;
				}
			}
		}while(end_flag == 0);
	}
 
		result = 1;
		for(i=0;i<index;i++){
//				printf("%d: cur=%lld, count=%d, check=%d\n",i,cur[i],count[i],check[i]);
			result *= int(pow(double(cur[i]),check[i]));
		//		if(check[i] > 0){
		//			for(j = 0 ;j<check[i];j++){
		//				result *= pow(cur[i]);
		//			}
		//			printf("%d: cur=%ld, count=%ld, check=%d\n",i,cur[i],count[i],check[i]);
		//		}
		}
	}
	printf("%lld\n",result);
	return 0;
 
}