#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int maxValue = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		maxValue = max(maxValue, p);
		total += p;
	}

	cout << total - maxValue / 2 << endl;


	
}
