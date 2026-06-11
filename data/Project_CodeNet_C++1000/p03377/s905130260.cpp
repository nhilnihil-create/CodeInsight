#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int a,b,x;
	scanf("%d %d %d",&a,&b,&x);

	if(x >= a && x <= a+b){

		printf("YES\n");

	}else{

		printf("NO\n");
	}

	return 0;
}
