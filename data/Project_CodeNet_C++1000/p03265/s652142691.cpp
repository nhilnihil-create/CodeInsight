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
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x = x2 - x1;
	int y = y2 - y1;
	cout << x2 - y << " " << y2 + x << " " << x1 - y << " " << y1 + x << endl;
}