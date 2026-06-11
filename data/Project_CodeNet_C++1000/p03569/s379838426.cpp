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
	string S, T;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != 'x') T.push_back(S[i]);
	}
	string R = T;
	reverse(R.begin(), R.end());
	int ans = 0;
	if (R != T) {
		cout << -1 << endl;
		return 0;
	}
	int N = S.size();
	int l = 0, r = N - 1;
	while (l < r) {
		//cout << l << " " << r << endl;
		if (S[l] != S[r]) {
			ans++;
			if (S[l] == 'x') l++;
			else r--;
		}
		else {
			l++; r--;
		}
	}
	cout << ans << endl;
}