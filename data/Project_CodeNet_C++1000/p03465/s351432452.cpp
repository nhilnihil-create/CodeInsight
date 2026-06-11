#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()

int main()
{
	int n; cin >> n;
	vector<int> a( n, 0 );
	REP( i, n ) cin >> a[i];
	int sum = accumulate( ALL( a ), 0 );

	bitset<4000010> set;
	set.set(0);
	REP( i, n ) set |= set << a[i];
	
	int cnt = 0;
	int l = ( sum + 1 ) / 2;
	REP( i, 4000010 )
	if( i >= l && set[i] )
	{
		cout << i << endl;
		break;
	}

	return 0;
}