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
	ll N, A, B, C, D, E;
	cin >> N >> A >> B >> C >> D >> E;
	ll num = min({ A,B,C,D,E });
	ll ans = 4;
	ans += (N + num - 1) / num;
	cout << ans << endl;
}