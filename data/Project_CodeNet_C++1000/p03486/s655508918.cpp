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
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());
	if (s < t) cout << "Yes" << endl;
	else cout << "No" << endl;
}