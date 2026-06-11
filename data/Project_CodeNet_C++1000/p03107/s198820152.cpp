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
	int b = 0, r = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') b++;
		else r++;
	}
	cout << min(b, r) * 2 << endl;
}