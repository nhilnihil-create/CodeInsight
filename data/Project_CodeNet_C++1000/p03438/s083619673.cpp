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

int a[100010], b[100010];
ll diff[2];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	for (int i = 0; i < N; i++) {
		if (a[i] > b[i]) diff[0] += a[i] - b[i];
		else diff[1] += (b[i] - a[i]) / 2;
	}
	if (diff[0] > diff[1]) cout << "No" << endl;
	else cout << "Yes" << endl;
}