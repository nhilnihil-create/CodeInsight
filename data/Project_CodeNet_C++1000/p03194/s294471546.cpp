#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long int

int main(int argc, const char * argv[]) {
	ll N,P;
	cin >> N >> P;
	if(N==1){
		cout << P << endl;
		return 0;
	}
	ll max = (int)pow(1.0*P,1.0/N);
	ll ret = 1;
	for (ll divider = 2; divider <= max && P!=1; ++divider) {
		ll count=0;
		while(P % divider == 0){
//			cerr << divider;
			count++;
			P /= divider;
		}
		if(count > 0){
//			cerr << divider << "**" << count << endl;
		}
		while(count>=N){
//			cerr << divider << endl;
			ret *= divider;
			count -= N;
		}
	}
	cout << ret << endl;
}
