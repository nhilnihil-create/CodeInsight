#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std ;

typedef unsigned long long ll ;
#define rep (i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ll N, P;
	
	cin >> N >> P;

	ll ret = 1;
	//cout << (ll)pow(P, 1.0 / N) << ";" << P << endl;
	ll rr = (ll)pow(P, 1.0 / N);

	if (pow(rr, N) < P)
	{
		if (pow(rr+1, N) == P)
		{
			rr++;
		}
	}

	for (ll i = rr; i >= 1; i--)
	{
		//cout << i << endl;

		ll tmp = pow(i, N);

		if (P % tmp == 0)
		{
			ret = i;
			break;
		}
		
	}
	
	cout << ret << endl;

	return 0;
}