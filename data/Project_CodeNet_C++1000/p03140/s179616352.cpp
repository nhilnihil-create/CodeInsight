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




ll N;
string A, B, C;

int main() {

	cin >> N >> A >> B >> C;

	ll ans = inf;
	ll sum = 0;

	rep(i, N) {
		if (A[i] == B[i] && A[i] !=  C[i]) {
			sum += 1;
		}

		else if (A[i] == C[i] && A[i] != B[i]) {
			sum += 1;

		}

		else if (B[i] == C[i] && A[i] != B[i]) {
			sum += 1;
		}
		else if(B[i] != C[i] && A[i] != B[i]){
			sum += 2;
		}

	}


	cout << sum << endl;

	return 0;
}