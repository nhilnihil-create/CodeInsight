#include<cstdio>
#include<vector>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;

int main(){
	unsigned N, M;
	scanf("%u %u", &N, &M);
	if(M == 1){ // n=1 の素因数分解は n^1
		printf("1\n");
		return 0;
	}
	vector<pair<unsigned, unsigned> > res;
	unsigned _M = M;
	for(unsigned i = 2; i*i <= M; ++i){
		unsigned count = 0;
		while(_M % i == 0){
			count++; // 素数i^{res[i]}
			_M /= i;
		}
		if(count) res.push_back(make_pair(i,count));
	}
	if(_M != 1) res.push_back(make_pair(_M, 1));
	vector<unsigned> divisor;
	divisor.push_back(1);
	for (unsigned i = 0; i < res.size(); ++i){
		vector<unsigned> to_add_divisor;
		unsigned multiple = 1;
		for (unsigned j = 0; j < res[i].second; ++j){
			multiple *= res[i].first;
			for (unsigned k = 0; k < divisor.size(); ++k){
				to_add_divisor.push_back(divisor[k]*multiple);
			}
		}
		for(unsigned j : to_add_divisor){
			divisor.push_back(j);
		}
	}
	sort(divisor.begin(), divisor.end(), greater<unsigned>());
	for(unsigned gcd : divisor){
		if(M/gcd >= N){
			printf("%u\n", gcd);
			return 0;
		}
	}
	return 0;
}