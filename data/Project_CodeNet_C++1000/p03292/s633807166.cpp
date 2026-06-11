#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int A[3];

	for(int i = 0; i < 3; i++){

		scanf("%d",&A[i]);
	}
	sort(A,A+3);

	printf("%d\n",(A[1]-A[0])+(A[2]-A[1]));

	return 0;
}
