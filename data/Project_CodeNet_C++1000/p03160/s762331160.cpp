#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

#define LP(_i,len) for(int _i=0;_i<len;++_i)
#define LP2(_i,_l,len) for(int _i=0,_l=len;_i<_l;++_i)
#define VLP(v,_itr,_end) for(auto _itr=v.begin(),_end=v.end();_itr!=_end;++_itr)
#define VCLP(v,_itr,_end) for(auto _itr=v.cbegin(),_end=v.cend();_itr!=_end;++_itr)

int abs(int x, int y) {
	return x >= 0 ? x : -x;
}

int main() {
	int N;
	cin >> N;

	vi h(N);
	VLP(h,itr,end)
		cin >> *itr;
	vi dps(N);
	LP(i,N)
	{
		if (i == 0) {
			dps[0] = 0;
			continue;
		}
		if (i == 1) {
			dps[1] = abs(h[0] - h[1]);
			continue;
		}
		int dp_1 = dps[i - 1] + abs(h[i - 1] - h[i]), dp_2 = dps[i - 2]
				+ abs(h[i - 2] - h[i]);
		dps[i] = dp_1 > dp_2 ? dp_2 : dp_1;
	}
	cout << dps[N - 1] << endl;
	return 0;
}