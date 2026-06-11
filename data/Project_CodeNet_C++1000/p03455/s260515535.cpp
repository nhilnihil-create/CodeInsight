#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n, a;
	cin >> n >> a;
	if (n * a % 2 != 0) {
		cout << "Odd" << endl;

	}
	else {
		cout << "Even" << endl;
	}
	return 0;
}