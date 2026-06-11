#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

struct Combination {
    int a;
    int b;
    int c;
};

using namespace std;

vector<Combination> v_c; 

void recursive_comb(vector<int>& indexes, int s, int rest, std::function<void(vector<int> &)> f) {
	if (rest == 0) {
		f(indexes);
	} else {
		if (s < 0) return;
		recursive_comb(indexes, s - 1, rest, f);
		indexes[rest - 1] = s;
		recursive_comb(indexes, s - 1, rest - 1, f);
	}
	return;
}

void foreach_comb(int n, int k, std::function<void(vector<int> &)> f) {
	vector<int> indexes(k);
	recursive_comb(indexes, n - 1, k, f);
	return;
}

int main() {
	int n;
	cin >> n;
	
	vector<long long int> v_num(5, 0);
	for (int i = 0; i < n; ++i) {
		string str; cin >> str;
		if (str[0] == 'M') v_num[0]++;
		if (str[0] == 'A') v_num[1]++;
		if (str[0] == 'R') v_num[2]++;
		if (str[0] == 'C') v_num[3]++;
		if (str[0] == 'H') v_num[4]++;
	}

	v_c.reserve(10);
	foreach_comb(5, 3, [](vector<int>& indexes) {
		Combination c{ indexes[0], indexes[1], indexes[2] };
		v_c.push_back(c);
	});

	long long int score = 0;
	for (int i = 0; i < v_c.size(); i++) {
		score += (v_num[v_c[i].a] * v_num[v_c[i].b] * v_num[v_c[i].c] );
	}

	cout << score << endl;

	return 0;
}
