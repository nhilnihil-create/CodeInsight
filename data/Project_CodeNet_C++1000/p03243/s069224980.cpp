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
const int MOD = 998244353;
const ll INF = 1000000000000000000;


int main()
{
	int N;
	cin >> N;
	for (int i = N; i < 1000; i++) {
		string S = to_string(i);
		bool ans = true;
		for (int j = 0; j < S.size() - 1; j++) {
			if (S[j] != S[j + 1]) {
				ans = false;
				break;
			}
		}
		if (ans) {
			cout << i << endl;
			return 0;
		}
	}
}