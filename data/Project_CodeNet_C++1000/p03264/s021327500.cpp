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
using ll = long long int;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
	
	int k;
	cin >> k;

	int x = 0, y = 0;
	rep(i, 1, k + 1) {
		if (i % 2 == 0) x++;
		else y++;
	}

	cout << x * y << endl;

	return 0;
}