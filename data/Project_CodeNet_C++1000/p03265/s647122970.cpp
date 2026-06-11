#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int dx = x2 - x1, dy = y1 - y2;

	cout << x2 + dy << " ";
	cout << y2 + dx << " ";
	cout << x1 + dy << " ";
	cout << y1 + dx << endl;

	return 0;
}
