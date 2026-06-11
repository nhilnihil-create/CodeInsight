#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 105

char table[NUM][NUM];

int main(){

	int A,B;
	scanf("%d %d",&A,&B);

	for(int row = 0; row <= 49; row++){
		for(int col = 0; col <= 99; col++){
			table[row][col] = '#';
		}
	}

	for(int row = 50; row <= 99; row++){
		for(int col = 0; col <= 99; col++){
			table[row][col] = '.';
		}
	}

	int count = 0;

	for(int row = 0; row <= 48 && count < A-1; row += 2){
		for(int col = 0; col <= 98 && count < A-1; col+= 2){

			table[row][col] = '.';
			count++;
		}
	}

	count = 0;

	for(int row = 99; row >= 51 && count < B-1; row -= 2){
		for(int col = 0; col <= 98 && count < B-1; col += 2){

			table[row][col] = '#';
			count++;
		}
	}

	printf("100 100\n");

	for(int row = 0; row < 100; row++){
		for(int col = 0; col < 100; col++){
			printf("%c",table[row][col]);
		}
		printf("\n");
	}


	return 0;
}
