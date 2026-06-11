#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	int A,B;
	scanf("%d %d",&A,&B);

	if(A >= 13){

		printf("%d\n",B);

	}else if(A >= 6){

		printf("%d\n",B/2);
	}else{

		printf("0\n");
	}

	return 0;
}
