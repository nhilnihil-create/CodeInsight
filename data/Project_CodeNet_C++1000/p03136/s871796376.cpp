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

	int total = 0;
	int maxNum = 0;
	vector<int> L;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		total += l;
		maxNum = max(maxNum, l);
		L.push_back(l);
	}

	if (total - maxNum > maxNum) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}




