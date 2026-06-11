#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main(){

	int D,N;

	scanf("%d %d",&D,&N);

	vector<int> V;

	int base;

	if(D == 0){

		base = 1;

	}else if(D == 1){

		base = 100;

	}else{

		base = 10000;
	}

	for(int i = 1; i <= 99; i++){

		V.push_back(base*i);
	}
	V.push_back(base*101);

	printf("%d\n",V[N-1]);

	return 0;
}
