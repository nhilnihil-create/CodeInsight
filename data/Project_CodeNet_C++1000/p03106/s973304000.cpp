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
	int A, B, K;
	cin >> A >> B >> K;
	for (int i = max(A, B); i > 0; i--) {
		if (A % i == 0 && B % i == 0) K--;
		if (K == 0) {
			cout << i << endl;
			return 0;
		}
	}
}
