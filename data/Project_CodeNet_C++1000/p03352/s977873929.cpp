#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int X;
	scanf("%d",&X);

	int ans = 0;
	for(int i = 1; i*i <= X; i++){

		int tmp = i*i;
		while(tmp*i > tmp && tmp*i <= X)tmp *= i;

		ans = max(ans,tmp);
	}

	printf("%d\n",ans);

	return 0;
}
