#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int N;
int A[105];


int main(){

	scanf("%d",&N);

	for(int i = 0; i < N; i++){

		scanf("%d",&A[i]);
	}

	int ans = 0;
	for(int i = 0; i < N-1; i++){
		for(int k = i+1; k < N; k++){

			ans = max(ans,abs(A[i]-A[k]));
		}
	}

	printf("%d\n",ans);

	return 0;
}
