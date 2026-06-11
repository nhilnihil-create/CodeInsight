#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	int N;
	cin >> N;
	uint32_t sum = 0;

	for (size_t i = 0; i < N; ++i)
	{
		uint32_t ai;
		cin >> ai;
		sum += ai;
	}

	cout << sum-N << endl;
}

int main() {

//	while(1)
		func();
	return 0;
}
