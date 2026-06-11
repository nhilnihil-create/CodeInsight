#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int N;
	scanf("%d",&N);

	bool FLG = false;

	for(int i = 0; 4*i <= N; i++){

		int tmp = 4*i;
		int rest = N-tmp;

		if(rest%7 == 0){

			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");

	return 0;
}
