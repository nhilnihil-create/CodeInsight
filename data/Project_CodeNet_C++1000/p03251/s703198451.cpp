#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int N,M,X,Y;
	scanf("%d %d %d %d",&N,&M,&X,&Y);

	int x_maxi = -BIG_NUM;
	int tmp;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		x_maxi = max(x_maxi,tmp);
	}

	int y_min = BIG_NUM;

	for(int i = 0; i < M; i++){

		scanf("%d",&tmp);
		y_min = min(y_min,tmp);
	}

	for(int Z = X+1; Z <= Y; Z++){

		if(Z > x_maxi && Z <= y_min){

			printf("No War\n");
			return 0;
		}
	}


	printf("War\n");

	return 0;
}
