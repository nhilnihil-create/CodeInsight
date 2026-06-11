#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e9+7;
const ll mod= 1e9 + 7;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	double D, N, M;
	cin >> N >> M >> D;
	CST(15);
	if(D!=0)cout << 2.0*(N - D)*(M - 1.0) / (N*N) << endl;
	else cout << (N - D)*(M - 1.0) / (N*N) << endl;

	return 0;
}