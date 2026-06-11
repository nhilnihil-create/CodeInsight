#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int maximum = 100000;
int dp[100001];

int main(){

	vector<int> V;

	V.push_back(1);

	int num = 6;

	for(int i = 1; ;i++){
		V.push_back(num);
		num *= 6;
		if(num > maximum)break;
	}

	num = 9;
	for(int i = 1; ;i++){
		V.push_back(num);
		num *= 9;
		if(num > maximum)break;
	}

	for(int i = 0; i <= maximum; i++){

		dp[i] = BIG_NUM;
	}
	dp[0] = 0;

	//ダブリングナップザック
	for(int i = 0; i < V.size(); i++){
		num = V[i];
		for(int k = 1; num <= maximum; k*=2){
			for(int a = maximum; a-num >= 0; a--){
				if(dp[a-num] == BIG_NUM)continue;

				dp[a] = min(dp[a],dp[a-num]+k);
			}
			num *= 2;
		}
	}

	int N;
	scanf("%d",&N);

	printf("%d\n",dp[N]);

	return 0;
}
