#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

typedef long long LL;
static LL INF = (1LL<<62);

int isPrime(LL p){
	if(p<=1) return 0;
	if(p==2 || p==3 || p==5 || p==7) return 1;
	if(p==4 || p==6 || p==8 || p==9) return 0;

	LL i;
	int ret = 1;
	for(i=2; i*i<=p; i++){
		if(p%i==0 && i!=p){
			ret = 0;
			break;
		}
	}
	return ret;
}

vector<LL> P55;
vector<LL> A;

void init(){
	LL i = 0;
	for(i = 2; i<=55555; i++){
		if(isPrime(i) == 1){
			P55.push_back(i);
		}
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	cin >> N;
	init();
	for(int i=0; i<P55.size(); i++){
		if((P55[i] % 5) == 1){
			A.push_back(P55[i]);
		}
	}

	for(int i=0; i<N; i++){
		printf("%lld", A[i]);
		if(i<N-1){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

