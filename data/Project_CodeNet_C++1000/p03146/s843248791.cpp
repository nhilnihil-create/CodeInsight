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

int a[110];
int cnt[1000010];
int main()
{
	int s;
	cin >> s;
	int ans = mod;
	int i = 0;
	for (int i = 0; i <= 1000000; i++) cnt[i] = 0;
	while (true) {
		if (cnt[s] >= 1) {
			cout << i + 1 << endl;
			return 0;
		}
		cnt[s]++;
		if (s % 2 == 0) s /= 2;
		else s = s * 3 + 1;
		i++;
	}
}
