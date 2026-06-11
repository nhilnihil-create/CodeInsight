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


int main() {
	int D, N;
	cin >> D >> N;
	int cnt = 0;
	for (int i = 1; i < mod; i++) {
		int c = 0;
		int tmp = i;
		while (tmp % 100 == 0) {
			tmp /= 100;
			c++;
		}
		if (c == D) cnt++;
		if (cnt == N) {
			cout << i << endl;
			return 0;
		}
	}
}
