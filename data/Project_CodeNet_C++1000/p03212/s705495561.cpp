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

int N;
string n;
vector<string> V;
void dfs(string S) {
	//cout << S << endl;
	if (S.size() <= n.size()) {
		for (int i = 3; i <= 7; i += 2) {
			V.push_back(S + (char)(i + '0'));
			dfs(S + (char)(i + '0'));
		}
	}
}
int main()
{
	cin >> N;
	n = to_string(N);
	int ans = 0;
	dfs("");
	for (string S : V) {
		//cout << S << endl;
		ll num = 0;
		bool c3 = false, c5 = false, c7 = false;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '3') c3 = true;
			if (S[i] == '5') c5 = true;
			if (S[i] == '7') c7 = true;
			num = num * 10 + S[i] - '0';
		}
		if (c3 && c5 && c7 && num <= N)ans++;
	}
	cout << ans << endl;
}
