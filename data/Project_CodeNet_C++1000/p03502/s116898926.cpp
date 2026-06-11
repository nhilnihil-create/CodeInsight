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

	int t = N;
	int c = 0;

	while (t > 0) {
		c += t % 10;
		t /= 10;
	}

	if (N % c == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}
