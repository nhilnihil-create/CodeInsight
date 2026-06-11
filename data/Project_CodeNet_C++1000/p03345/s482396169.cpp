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
	ll A, B, C, K;
	cin >> A >> B >> C >> K;
	if (K % 2 == 0) cout << A - B;
	else cout << B - A;
}