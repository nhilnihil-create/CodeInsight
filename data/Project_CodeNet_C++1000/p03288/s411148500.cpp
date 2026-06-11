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
	int R;
	cin >> R;
	if (R < 1200) cout << "ABC" << endl;
	else if (R >= 2800) cout << "AGC" << endl;
	else cout << "ARC" << endl;
}