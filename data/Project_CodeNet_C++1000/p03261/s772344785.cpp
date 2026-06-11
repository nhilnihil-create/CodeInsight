#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	bool ok = true;
	map<string, int> m;
	char moji;
	for (int ii = 0; ii < N; ++ii){
		string w;
		cin >> w;

		if (ii > 0){
			if(m[w] || w[0] != moji){
				ok = false;
				break;
			}
		}

		m[w] = 1;
		moji = w[w.size()-1];
	}

	if (ok){
	cout << "Yes" << "\n";
	} else {
	cout << "No" << "\n";
	}


	return 0;
}
