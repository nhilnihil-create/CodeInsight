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
	int N, M;
	cin >> N >> M;
	vector<int> R;
	for (int i = 1; i * i <= M; i++) {
		if (M % i == 0) {
			R.push_back(i);
			if (i * i != M) R.push_back(M / i);
		}
	}
	sort(R.begin(), R.end());
	for (int i = R.size() - 1; i >= 0; i--) {
		//cout << R[i] << endl;
		if (M / R[i] >= N) {
			cout << R[i] << endl;
			return 0;
		}
	}
}