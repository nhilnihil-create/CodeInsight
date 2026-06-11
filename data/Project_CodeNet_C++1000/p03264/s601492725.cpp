#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int K;
	scanf("%d",&K);

	int GU = 0,KI = 0;
	for(int i = 1; i <= K; i++){
		if(i%2 == 1){

			KI++;

		}else{

			GU++;
		}
	}

	printf("%d\n",GU*KI);

	return 0;
}
