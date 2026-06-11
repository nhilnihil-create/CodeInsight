#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	vector<int> v(3,0);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cout << v[0] + v[1] + v[2] * 10 << endl;
	return 0;
}
