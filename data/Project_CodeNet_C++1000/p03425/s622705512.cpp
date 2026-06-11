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

	long long N;
	cin >> N;

	string march = "MARCH";

	vector<vector<string>> S(march.length(), vector<string>());

	string str;
	size_t pos = 0;
	for (long long i = 0; i < N; i++) {
		cin >> str;
		pos = march.find(str.substr(0, 1));
		if (pos != string::npos) {
			S[pos].push_back(str);
		}
	}

	long long ans = 0;
	for (size_t i = 0; i < S.size() - 2; i++) {
		for (size_t j = i + 1; j < S.size() - 1; j++) {
			for (size_t k = j + 1; k < S.size(); k++) {
				ans += (long long)S[i].size() * (long long)S[j].size() * (long long)S[k].size();
			}
		}
	}

	cout << ans << endl;

	return 0;
}