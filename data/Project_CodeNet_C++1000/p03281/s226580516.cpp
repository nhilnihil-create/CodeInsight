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

	int ans = 0;

	for(int i = 3; i <= N; i+=2){

		int tmp = 0;
		for(int k = 1; k*k <= i; k++){
			if(i%k != 0)continue;
			int another = i/k;

			if(k != another){

				tmp += 2;

			}else{

				tmp += 1;
			}

		}
		if(tmp == 8){

			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
