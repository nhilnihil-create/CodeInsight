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

int ans[1 << 19];
int main()
{
	int M, K;
	cin >> M >> K;
	if (K >= (1 << M)) {
		cout << -1 << endl;
	}
	else if (M == 1) {
		if (K == 0) {
			for (int i = 0; i <= 1; i++) {
				cout << i << " " << i << " ";
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		vector<int> ans;
		vector<int> rans;
		for (int i = 0; i < (1 << M); i++) {
			if (i == K)  continue;
			ans.push_back(i);
		}
		rans = ans;
		reverse(rans.begin(), rans.end());
		cout << K << " ";
		for (int num : ans) cout << num << " ";
		cout << K << " ";
		for (int num : rans) cout << num << " ";
		cout << endl;
	}
}