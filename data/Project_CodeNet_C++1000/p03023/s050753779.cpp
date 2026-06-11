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


int main()
{
	ull n;cin>>n;
	cout << n*180-360 << endl;
	return 0;
}