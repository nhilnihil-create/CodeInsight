#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

typedef long long ll;

#define INF 100000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define eps 1.0e-14;

using pint = pair<ll,ll>;

int main(){
	int a,b; cin >> a >> b;
	cout << ((a*3)+b)/2 << endl;
	return 0;
}