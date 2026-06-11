#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(a) (a).begin(),(a).end()
#define PI 3.141592653589793238
#define INF 1050000000

using vi = vector<int>;


int main() {

	vi v(3);

	REP(i, 3) {
		cin >> v[i];
	}

	sort(ALL(v));
	
	
	cout << v[2]*10+v[1]+v[0] << endl;

	return 0;
}