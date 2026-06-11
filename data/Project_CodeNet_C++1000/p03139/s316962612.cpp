#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <functional>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))



using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;
const ll inf = (1LL << 60);
const ll mod = 1000000007;


ll N, M, K;


ll dp[2][1003];
ll sum[1003];

vector<ll> a;


ll A, B;

int main() {
	cin >> N >> A >> B;

	cout << MIN(A, B) << " " <<  MAX((A + B) - N, 0) << endl;





	return 0;
}