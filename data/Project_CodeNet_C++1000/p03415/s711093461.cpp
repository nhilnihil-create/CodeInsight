#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define PI 3.141592653589793238
#define INF 1050000000

using vi = vector<int>;


int main() {

	char c;
	string ans = "";

	for (int i = 0; i < 9; i++)
	{
		cin >> c;
		if (i == 0 || i == 4 || i == 8) {
			ans += c;
		}
	}

	cout << ans << endl;

	return 0;
}