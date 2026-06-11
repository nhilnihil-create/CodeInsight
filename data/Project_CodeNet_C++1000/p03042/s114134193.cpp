#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


char buf[5];

int main(){

	scanf("%s",buf);

	int A = 10*(buf[0]-'0')+(buf[1]-'0');
	int B = 10*(buf[2]-'0')+(buf[3]-'0');

	if(A >= 1 && A <= 12 && B >= 1 && B <= 12){

		printf("AMBIGUOUS\n");
	}else if(A >= 1 && A <= 12){

		printf("MMYY\n");

	}else if(B >= 1 && B <= 12){

		printf("YYMM\n");
	}else{

		printf("NA\n");
	}

	return 0;
}
