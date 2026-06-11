#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	vector<int> x(N), y(M);
	for (auto& e : x) cin >> e;
	x.push_back(X);
	for (auto& e : y) cin >> e;
	y.push_back(Y);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	if (x.back() < y.front()) {
		cout << "No War" << endl;
	}
	else {
		cout << "War" << endl;
	}
}
