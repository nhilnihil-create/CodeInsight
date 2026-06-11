#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()

#define cMOD 1000000007ULL
#define cINF ((1ull<<62)-1)
#define cINFINT ((1<<30)-1)

// N=2000 の O( N^3 ) は bitsetの可能性あり

int main()
{
	ull n = 0;
	cin >> n;
	vector<ll> a( n, 0 );
	REP(i, n) cin >> a[i];
	
	bitset<2000*2000/2+1> bs(1);
	REP(i,n) bs |= bs<<a[i];
	
	ll sum = accumulate( ALL(a), 0 );
	for( ll i = sum / 2; i >= 0; --i )
		if( bs[i] ) { cout << sum - i << endl; break; }

	return 0;
}