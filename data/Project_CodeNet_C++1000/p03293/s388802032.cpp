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
	cin >> S >> T;
	int N = S.size();
	S += S;
	for (int i = 0; i < N; i++) {
		if (S.substr(i, N) == T) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
