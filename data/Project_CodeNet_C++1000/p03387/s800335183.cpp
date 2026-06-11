#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int table[3];
	int maximum = -1;

	for(int i = 0; i < 3; i++){

		scanf("%d",&table[i]);
		maximum = max(maximum,table[i]);
	}

	int ans = 0;
	for(int i = 0; i < 3; i++){

		int add = (maximum-table[i])/2;
		ans += add;
		table[i] += 2*add;
	}

	int count = 0;
	for(int i = 0; i < 3; i++){

		if(table[i] != maximum){

			count++;
		}
	}

	if(count == 1){

		ans += 2;

	}else if(count == 2){

		ans++;
	}

	printf("%d\n",ans);

	return 0;
}
