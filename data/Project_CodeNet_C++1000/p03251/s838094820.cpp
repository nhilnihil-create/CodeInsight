#include<stdio.h>

int main(){
	
	int N, M, X, Y;
	
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	
	int kotaX[100000];
	int kotaY[100000];
	int maxX = -123456;
	int minY = 2 << 29;
//	printf("%d\n", minY);
	for(int i = 0; i < N; i++){
		scanf("%d", &kotaX[i]);
		if(kotaX[i] > maxX){
			maxX = kotaX[i];
		}
	}
	for(int i = 0; i < M; i++){
		scanf("%d", &kotaY[i]);
		if(kotaY[i] < minY){
			minY = kotaY[i];
		}
	}
	
	bool isFalse = false;
	
	if(minY <= X || minY > Y){
		isFalse = true;
	}
	for(int i = 0; i < N; i++){
		if(kotaX[i] >= minY){
			isFalse = true;
		}
	}
	
	if(isFalse == true){
		printf("War\n");
	}
	else{
		printf("No War\n");
	}
	
//	printf("%d %d", maxX, minY);
	
	
	
	return 0;
}