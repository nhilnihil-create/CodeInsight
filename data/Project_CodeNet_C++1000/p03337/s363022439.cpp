#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> vi;

int main() {

	ll a, b;
	cin >> a >> b;
	
	vi.push_back(a + b);
	vi.push_back(a - b);
	vi.push_back(a * b);
	
	sort(vi.begin(), vi.end());
	cout << vi.back() << '\n';
	return 0;
}
