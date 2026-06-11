#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int N,M;

	scanf("%d %d",&N,&M);

	vector<int> V;

	int ans = -1;

	for(int i = 1; i*i <= M; i++){
		if(M%i != 0)continue;

		if(i >= N){

			ans = max(ans,M/i);
		}
		if(M/i >= N){

			ans = max(ans,i);
		}
	}

	printf("%d\n",ans);

	return 0;
}
