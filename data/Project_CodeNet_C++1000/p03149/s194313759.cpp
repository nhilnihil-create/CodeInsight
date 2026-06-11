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

int cnt[10];
int main()
{
	for (int i = 0; i < 4; i++) {
		int N;
		cin >> N;
		cnt[N]++;
	}
	if (cnt[1] == 1 && cnt[4] == 1 && cnt[7] == 1 && cnt[9] == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
}
