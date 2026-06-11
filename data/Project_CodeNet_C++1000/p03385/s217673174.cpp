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
	if (S[0] == S[1] || S[1] == S[2] || S[0] == S[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}