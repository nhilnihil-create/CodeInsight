#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);

	if(abs(a-c) <= d || (abs(a-b) <= d && abs(c-b) <= d)){

		printf("Yes\n");

	}else{

		printf("No\n");
	}

	return 0;
}
