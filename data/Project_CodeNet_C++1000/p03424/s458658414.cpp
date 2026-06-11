#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N; cin >> N;

	set<string> S;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;

		S.insert(s);

	}

	if (S.size() == 3) {
		cout << "Three" << endl;
	}else if (S.size() == 4) {
		cout << "Four" << endl;
	}

	return 0;
}
