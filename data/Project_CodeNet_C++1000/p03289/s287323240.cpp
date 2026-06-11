#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main(){

	char S[11];

	scanf("%s",S);

	int len;
	for(len = 0; S[len] != '\0'; len++);

	if(S[0] != 'A'){

		printf("WA\n");
		return 0;
	}

	int count = 0;
	for(int i = 2; i <= len-2; i++){
		if(S[i] == 'C')count++;
	}

	if(count != 1){

		printf("WA\n");
		return 0;
	}

	int num_small = 0;
	for(int i = 0; i < len; i++){
		if(S[i] >= 'a' && S[i] <= 'z'){

			num_small++;
		}
	}

	if(num_small+2 != len){

		printf("WA\n");
		return 0;
	}

	printf("AC\n");

	return 0;
}
