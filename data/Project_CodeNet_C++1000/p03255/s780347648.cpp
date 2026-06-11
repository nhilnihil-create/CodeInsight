#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<climits>
using namespace std;

int N;
long long X;
vector<long long> x;
vector<long long> imos;

long long calc(int n)
{
	long long ret = (N + n) * X;
	long long sum;
	for(int i=N, w=1; i>0; i-=n, w++){
		long long d = imos[i] - imos[max(0, i-n)];

		if(w == 1)
			sum= 5 * d;
		else{
			if(d <= (LLONG_MAX/(w*2+1)))
				sum = (w*2 + 1) * d;
			else
				return LLONG_MAX;
		}

		if(ret <= LLONG_MAX-sum)
			ret += sum;
		else
			return LLONG_MAX;
	}

	return ret;
}

int main(void)
{
	cin >> N >> X;

	x = vector<long long>(N);
	for(int i=0; i<N; i++)
		cin >> x[i];
	
	imos = vector<long long>(N+1, 0);
	for(int i=0; i<N; i++)
		imos[i+1] = imos[i] + x[i];

	long long ret = LLONG_MAX;
	for(int i=1; i<=N; i++){
		ret = min(ret, calc(i));
	}

	cout << ret << endl;

	return 0;
}
