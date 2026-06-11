#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	ll K, A, B;
	cin >> K >> A >> B;
	if (B - A <= 2) {
		cout << K + 1 << endl;
	}
	else {
		if (A >= K) {
			cout << K + 1 << endl;
		}
		else {
			K -= A - 1;
			K -= 2;
			cout << B + (B - A) * (K / 2) + (K % 2) << endl;
		}
	}
	return 0;
}