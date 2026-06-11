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


ll N, A, B;


vector<ll> a;

int main() {
	cin >> N;

	ll v;

	rep(i, N) {
		cin >> v;
		a.push_back(v);
	}

	ll index = 0;
	ll m = 0;
	rep(i, N) {
		if (abs(a[i]) > m) {
			index = i;
			m = abs(a[i]);
		}
	}
	cout << 2 * N << endl;
	if (a[index] > 0) {
		
		cout << index+1 << " " << N << endl;
		cout << index+1 << " " << N << endl;
		for (int i = 2; i <= N; i++) {
			cout << N << " " << N << endl;
			cout << N << " " << i << endl;
			
		}


	}
	else {
		cout << index + 1 << " " << 1 << endl;
		cout << index + 1 << " " << 1 << endl;
		for (int i = N-1; i >= 1; i--) {
			cout << 1 << " " << 1 << endl;
			cout << 1 << " " << i << endl;
		}

	}



	return 0;
}