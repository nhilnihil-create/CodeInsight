#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

#define REPI(_i,len) for(int _i=0;_i<len;++_i)
#define REPI2(_i,_l,len) for(int _i=0,_l=len;_i<_l;++_i)
#define VREP(v,_itr,_end) for(auto _itr=v.begin(),_end=v.end();_itr!=_end;++_itr)
#define VCREP(v,_itr,_end) for(auto _itr=v.cbegin(),_end=v.cend();_itr!=_end;++_itr)

int abs(int x, int y) {
	return x >= 0 ? x : -x;
}

int main() {
	int N, K;
	cin >> N >> K;

	vi h(N);
	VREP(h,itr,end)
		cin >> *itr;
	vi dps(N);
	REPI(i,N)
	{
		int min1 = 0; //i==0
		for (int j = 1, len = min(i, K); j <= len; ++j) {
			int dp1 = dps[i - j] + abs(h[i - j] - h[i]);
			if (j == 1 || dp1 < min1) {
				min1 = dp1;
			}
		}
		dps[i] = min1;
	}
	cout << dps[N - 1] << endl;
	return 0;
}
