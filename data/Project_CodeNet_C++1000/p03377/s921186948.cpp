#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	int A, B, X;
	cin >> A >> B >> X;
	if (A <= X && X - A <= B)cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
