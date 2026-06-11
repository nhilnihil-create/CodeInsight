#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	int a,b;
	scanf("%d %d",&a,&b);

	if(a <= b){

		printf("%d\n",a);

	}else{

		printf("%d\n",a-1);
	}

	return 0;
}
