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
	int N, M;
	cin >> N;
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		int D;
		cin >> D;
		mp[D]++;
	}
	cin >> M;
	bool out = false;
	for (int i = 0; i < M; i++) {
		int T;
		cin >> T;
		if (mp[T] <= 0) out = true;
		mp[T]--;
	}
	if (!out)cout << "YES" << endl;
	else cout << "NO" << endl;
}