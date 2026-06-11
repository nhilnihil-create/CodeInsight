#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int N, M;
map<int, pair<int, int>> C;	 // Year, pair<ID, refecture>
string ID[MAX + 1];
int prefCities[MAX + 1];

string fillZero(string s) {
	while (s.size() < 6) {
		s = "0" + s;
	}
	return s;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int p, y;
		cin >> p >> y;
		ID[i] = fillZero(to_string(p));
		C[y] = make_pair(i, p);
	}
	for (int i = 1; i <= N; i++) {
        prefCities[i] = 0;
	}
	for (auto it = C.begin(); it != C.end(); it++) {
		ID[(*it).second.first] +=
			fillZero(to_string(++prefCities[(*it).second.second]));
	}
	for (int i = 1; i <= M; i++) {
		cout << ID[i] << endl;
	}
	return 0;
}
