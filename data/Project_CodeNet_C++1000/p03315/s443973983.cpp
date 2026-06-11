#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	char S[5];
	scanf("%s",S);

	int num = 0;
	for(int i = 0; S[i] != '\0'; i++){

		if(S[i] == '+'){

			num++;
		}else{

			num--;
		}
	}

	printf("%d\n",num);

	return 0;
}
