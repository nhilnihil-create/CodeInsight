#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-7
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

int main() {
	speed;
	string s;
	cin >> s;
	int a = 0;
	for (int i = 0; i < 4; ++i)
		if (s[i] == '2') ++ a;
	cout << a;
}