#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int maxNum = 0;
	int minNum = pow(10, 9);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		maxNum = max(maxNum, a);
		minNum = min(minNum, a);
	}

	cout << abs(maxNum - minNum) << endl;
}




