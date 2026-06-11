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

	string s;

	cin >> s;

	int a=0;

	for (int i = 0; i < 3; i++)
	{
		if (s[i] == 'o')a++;
	}

	cout << 700+100*a << endl;

	return 0;
}