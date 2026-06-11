#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	int a1, a2, a3;
	cin>> a1 >> a2 >> a3;

	vector<uint16_t> costs(3);
	costs[0] = abs(a1 - a2);
	costs[1] = abs(a1 - a3);
	costs[2] = abs(a2 - a3);

	sort(costs.begin(), costs.end());

	cout << costs[0] + costs[1] << endl;

}

int main() {

//	while(1)
		func();
	return 0;
}
