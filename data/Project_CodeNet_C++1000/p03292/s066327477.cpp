#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<list>
using namespace std;

int main() {

	vector<int> A(3, 0);

	cin >> A[0] >> A[1] >> A[2];

	cout << *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end()) << endl;

	return 0;
}
