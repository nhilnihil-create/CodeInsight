#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	char buf[4];

	scanf("%s",buf);

	int ans = 700;
	for(int i = 0; i < 3; i++){

		if(buf[i] == 'o'){

			ans += 100;
		}
	}

	printf("%d\n",ans);

	return 0;
}
