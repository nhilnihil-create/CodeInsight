#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int count = 0;
	for (int i = 0; i < 2; i++) {
		if (A >= B) {
			count += A;
			A -= 1;
		}
		else {
			count += B;
			B -= 1;
		}
	}
	cout << count << endl;

}




