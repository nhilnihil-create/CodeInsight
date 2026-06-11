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

int cnt[3];
int main()
{
	int N, A, B;
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if (p <= A) cnt[0]++;
		else if (p >= B + 1) cnt[2]++;
		else cnt[1]++;
	}
	cout << min({ cnt[0],cnt[1],cnt[2] }) << endl;
}
