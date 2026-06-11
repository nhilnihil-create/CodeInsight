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

	vector<int> A;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());

	cout << A[A.size() - 1] - A[0] << endl;
	
}
