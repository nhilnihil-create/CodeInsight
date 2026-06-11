#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int POW[20];

int main(){

	POW[0] = 1;
	for(int i = 1; i < 20; i++){

		POW[i] = POW[i-1]*2;
	}

	int M,K;
	scanf("%d %d",&M,&K);

	if(M == 1){

		if(K == 0){

			printf("0 0 1 1\n");

		}else{

			printf("-1\n");
		}

		return 0;
	}

	if(K >= POW[M]){

		printf("-1\n");
		return 0;
	}

	vector<int> A,B;
	for(int i = 0; i < POW[M]; i++){
		if(i == K)continue;

		A.push_back(i);
		B.push_back(i);
	}
	A.push_back(K);
	for(int i = B.size()-1; i >= 0; i--){

		A.push_back(B[i]);
	}
	A.push_back(K);

	printf("%d",A[0]);

	for(int i = 1; i < A.size(); i++){

		printf(" %d",A[i]);
	}
	printf("\n");

	return 0;
}
