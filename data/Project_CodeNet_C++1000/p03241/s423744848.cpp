#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

int main(){
	unsigned N, M;
	scanf("%u %u", &N, &M);
	vector<unsigned> divisor;
	for (unsigned i = 1; i*i <= M; ++i){
	if(!(M%i)){
		divisor.push_back(i);
			if(i != M/i) divisor.push_back(M/i);
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