#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int tmp;
	vector<int> V;

	for(int i = 0; i < 3; i++){
		scanf("%d",&tmp);
		V.push_back(tmp);
	}

	sort(V.rbegin(),V.rend());

	printf("%d\n",10*V[0]+V[1]+V[2]);


	return 0;
}
