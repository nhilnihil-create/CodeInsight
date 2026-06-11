#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A1, A2, A3;
	cin >> A1 >> A2 >> A3;

	vector<int> A;
	A.push_back(A1);
	A.push_back(A2);
	A.push_back(A3);
	
	sort(A.begin(), A.end());

	cout << abs(A[1] - A[0]) + abs(A[2] - A[1]) << endl;
	
}
