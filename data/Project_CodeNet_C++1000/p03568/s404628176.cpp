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
	int N;
	cin >> N;
	int ans = 1;
	int minus = 1;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		ans *= 3;
		if (A % 2 == 0) minus *= 2;
	}
	cout << ans - minus << endl;
}
