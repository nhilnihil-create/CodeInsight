#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 60000

bool check[SIZE];

int main(){

	for(int i = 0; i < SIZE; i++){

		check[i] = true;
	}
	check[1] = false;
	vector<int> V;

	for(int i = 2; i < SIZE; i++){
		if(!check[i])continue;
		if(i%10 == 7){

			V.push_back(i);
		}

		for(int k = 2*i; k < SIZE; k += i){

			check[k] = false;
		}
	}


	int N;
	scanf("%d",&N);

	printf("%d",V[0]);
	for(int i = 1; i < N; i++){

		printf(" %d",V[i]);
	}
	printf("\n");

	return 0;
}
