#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int N,X;
	scanf("%d %d",&N,&X);

	int sum = 0,minimum = BIG_NUM,tmp;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		sum += tmp;
		minimum = min(minimum,tmp);
	}

	X -= sum;
	int ans = N;

	ans += X/minimum;

	printf("%d\n",ans);

	return 0;
}
