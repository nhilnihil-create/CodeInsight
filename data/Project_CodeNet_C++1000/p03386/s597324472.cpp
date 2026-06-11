#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int A,B,K;
	scanf("%d %d %d",&A,&B,&K);

	vector<int> V;

	for(int i = 0; i < K && A+i <= B; i++){

		V.push_back(A+i);
	}
	for(int i = 0; i < K && B-i >= A; i++){

		V.push_back(B-i);
	}

	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());

	for(int i = 0; i < V.size(); i++){

		printf("%d\n",V[i]);
	}

	return 0;
}
