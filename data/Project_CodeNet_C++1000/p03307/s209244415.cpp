#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	uint32_t N;
	cin >> N;
	if (N%2 == 0)
		cout << N << endl;
	else
		cout << 2*N << endl;
}

int main() {

	func();
	return 0;
}
