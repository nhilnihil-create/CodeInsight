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
	string S;
	cin >> S;
	int ans = mod;
	for (int i = 0; i < S.size(); i++) {
		int n = stoi(S.substr(i, 3));
		//cout << n << endl;
		ans = min(ans, abs(753 - n));
	}
	cout << ans << endl;
}
