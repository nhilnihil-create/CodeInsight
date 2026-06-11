#include <queue>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int ll;

#define EPS (1e-9)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(int i=0;i<n;i++)

/*
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
*/

string S;

int main()
{
	cin >> S;
	REP(i, S.length() - 8) {
		cout << S[i];
	}
	cout << endl;
}