#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N, A, B;
	cin >> N >> A >> B;

	if (N >= A + B) {
		cout << min(A, B) <<" "<< 0 << endl;
	}
	else {
		cout << min(A, B) << " " << A+B-N << endl;
	}
}
