#include <iostream>
#include <algorithm>

using std::cout;    using std::cin;
using std::endl;	using std::max;

int main() {
	
	int N;
	cin >> N;
	
	int m = 0, sum = 0;
	
	for (int i = 0; i != N; ++i) {
		
		int x;
		cin >> x;
		
		sum += x;
		m = max(m, x);
	}
	
	if (sum > 2 * m)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
		
	return 0;
}