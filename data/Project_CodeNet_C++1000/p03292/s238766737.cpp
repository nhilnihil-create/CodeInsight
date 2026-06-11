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

	vector<int> v(3);

	for (int i = 0; i < 3; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	cout << v[0]-v[2] << endl;


	return 0;
}