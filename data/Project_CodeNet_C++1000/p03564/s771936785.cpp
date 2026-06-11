#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int num = 1;
	for (int i = 0; i < N; i++) {
		int a = num * 2;
		int b = num + K;

		if (a < b) {
			num = num * 2;
		}
		else {
			num = num + K;
		}
	}
	cout << num << endl;
}
