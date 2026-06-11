#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	uint32_t N, maxAi(0), minAi(UINT32_MAX);
	cin >> N;
	for (size_t i = 0; i < N; ++i)
	{
		uint32_t Ai;
		cin >> Ai;
		maxAi = max(Ai, maxAi);
		minAi = min(Ai, minAi);
	}
	cout << maxAi - minAi << endl;
}

int main() {

//	while(1)
		func();
	return 0;
}
