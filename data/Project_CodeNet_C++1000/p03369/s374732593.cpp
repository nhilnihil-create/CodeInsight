#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {
	
	string s; cin >> s;

	int sum = 700;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == 'o') {
			sum += 100;
		}
	}
	cout << sum << endl;

	return 0;
}
