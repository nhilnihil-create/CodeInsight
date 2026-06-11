#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	typedef pair<long long, pair<int, int>> HP;
	vector<HP> Happiness(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		Happiness[i] = { (long long)a + b,{a,b} };
	}
	sort(Happiness.begin(), Happiness.end(), greater<HP>());
	long long Taka = 0, Aoki = 0;
	for (int i = 0; i < N; i += 2) Taka += Happiness[i].second.first;
	for (int i = 1; i < N; i += 2) Aoki += Happiness[i].second.second;
	cout << Taka - Aoki << endl;
}
