#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;

int main(void)
{
	long long N, P;
	cin >> N >> P;

	if(N == 1){
		cout << P << endl;

		return 0;
	}
	
	long long ans = 1;
	for(long long i=2; i*i<=P; i++){
		long long cnt = 0;
		long long p = P;
		while(p%i == 0){
			cnt++;
			p /= i;
		}

		if(cnt >= N)
			ans = i;
	}
	
	cout << ans << endl;

	return 0;
}
