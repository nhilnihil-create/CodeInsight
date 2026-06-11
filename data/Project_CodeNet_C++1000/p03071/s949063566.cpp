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
	int A, B;
	cin >> A >> B;
	int ans = 0;
	if (A >= B) {
		ans += A;
		A--;
	}
	else {
		ans += B;
		B--;
	}
	if (A >= B) {
		ans += A;
		A--;
	}
	else {
		ans += B;
		B--;
	}
	cout << ans << endl;
}
