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
	int A, B;
	cin >> A >> B;
	if (A <= 5) cout << 0 << endl;
	else if (A >= 13) cout << B << endl;
	else cout << B / 2 << endl;
}