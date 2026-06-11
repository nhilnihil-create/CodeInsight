#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N;
int POW[31];

int main(){

	POW[0] = 1;
	for(int i = 1; i <= 30; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d",&N);

	int tmp,ans = 0;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		for(int k = 30; k >= 0; k--){
			if(tmp%POW[k] == 0){

				ans += k;
				break;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}
