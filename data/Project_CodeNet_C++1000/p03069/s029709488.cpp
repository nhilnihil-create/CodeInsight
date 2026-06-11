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
	int N;
	string S;
	cin >> N >> S;
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '.')  sum++;
	}
	ans = sum;
	for (int i = 0; i < N; i++) {
		if (S[i] == '.')sum--;
		else sum++;
		ans = min(ans, sum);
	}
	cout << ans << endl;
}