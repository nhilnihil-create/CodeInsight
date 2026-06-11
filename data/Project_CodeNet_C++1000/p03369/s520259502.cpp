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
	int ans = 700;
	for (int i = 0; i < 3; i++) {
		if (S[i] == 'o') ans += 100;
	}
	cout << ans << endl;
}
