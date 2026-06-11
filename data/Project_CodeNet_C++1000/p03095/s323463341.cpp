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

int cnt[26];
int main()
{
	int N;
	string S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cnt[S[i] - 'a']++;
	}
	ll ans = 1;
	for (int i = 0; i < 26; i++) {
		ans = (ans * (cnt[i] + 1)) % mod;
	}
	cout << ans - 1 << endl;
}
