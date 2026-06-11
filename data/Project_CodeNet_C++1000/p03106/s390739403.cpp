#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(void)

{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, A, B;
	cin >> A >> B >> N;
	int min = (A <= B) ? A : B;
	vector<int> result;
	for (int i = 1; i <= min; i++)
	{
		if (A % i == 0 && B % i == 0)
			result.push_back(i);
	}
	sort(result.begin(), result.end());

	cout << result[result.size() - N];
	return 0;
}
