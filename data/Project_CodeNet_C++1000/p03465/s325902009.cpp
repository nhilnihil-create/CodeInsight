#include <bits/stdc++.h>
using namespace std;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)

int main()
{
	int n; cin>>n;
	bitset<2000*2000/2+1> bs(1);
	int sum = 0;
	REP(i,n) { int c; cin>>c; bs |= bs<<c; sum += c; }
	for( int i = sum / 2; i >= 0; --i )
		if( bs[i] ) { cout << sum - i << endl; break; }

	return 0;
}