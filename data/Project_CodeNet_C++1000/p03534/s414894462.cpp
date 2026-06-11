#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;

using namespace std;

int main()
{
	string S;
	cin >> S;

	int n[3] = { 0,0,0 };
	REP(i, S.length())
	{
		n[(int)(S[i] - 'a')]++;
	}

	int max = std::max(n[0], std::max(n[1], n[2]));
	int min = std::min(n[0], std::min(n[1], n[2]));

	if (max - min < 2)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}