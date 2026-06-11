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
	int ans = 0;
	cin >> S;
	for (int i = 0; i < 4; i++) {
		if (S[i] == '+') ans++;
		else ans--;
	}
	cout << ans << endl;
}