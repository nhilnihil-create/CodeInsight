#include <iostream> 
#include <algorithm>  
using namespace std;

int main() {
	int n,g;
	cin >> n;
	cin >> g;
	for(int i = 1,x; i < n; ++i) {
		cin >> x;
		g = __gcd(x, g);
	}
	cout << g << '\n';
	return 0;
}