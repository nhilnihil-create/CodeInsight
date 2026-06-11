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
	int w;
	cin >> S >> w;
	string ans;
	for (int i = 0; i < S.size(); i += w) ans += S[i];
	cout << ans << endl;
}