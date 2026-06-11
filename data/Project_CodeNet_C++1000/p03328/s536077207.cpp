#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	int table[1000];

	for(int i = 1; i <= 999; i++){

		table[i] = (i*(i+1))/2;
	}

	int a,b;
	scanf("%d %d",&a,&b);

	for(int i = 1; i <= 998; i++){

		if(table[i+1]-table[i] == b-a){

			printf("%d\n",table[i]-a);
			return 0;
		}
	}

	return 0;
}
