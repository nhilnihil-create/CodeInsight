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

	if (N % 111 == 0) {
		cout << N << endl;
	}
	else {
		int next = N;
		while (next % 111 != 0) {
			next++;
		}
		cout << next << endl;
	}


	
}
