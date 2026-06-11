#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a.at(i);
		b.at(i) = a.at(i);
	}
	sort(b.begin(), b.end());

	for (int i = 0; i < N; i++) {
		if (a.at(i) <= b.at((N / 2)-1))cout << b.at(N / 2)<<endl;
		else cout << b.at(N / 2 - 1) << endl;
	}
	
	return 0;
}
