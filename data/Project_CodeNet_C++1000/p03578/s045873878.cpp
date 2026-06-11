#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	int N;
	cin >> N;
	list<int> D;
	int v;
	for (int i = 0; i < N; i++) {
		cin >> v;
		D.push_back(v);
	}

	D.sort();

	int M;
	cin >> M;
	list<int> T;
	for (int i = 0; i < M; i++) {
		cin >> v;
		T.push_back(v);
	}

	T.sort();

	bool jdg = true;

	auto pos = D.begin();

	for (auto itr = T.begin(); itr != T.end(); itr++) {
		while (pos != D.end()) {
			if (*pos == *itr) {
				break;
			}
			pos++;
		}
		if (pos == D.end()) {
			jdg = false;
			break;
		}
		else {
			pos++;
		}
	}

	if (jdg == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;

	}

	return 0;
}