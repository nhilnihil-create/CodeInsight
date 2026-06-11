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

	while (1) {
		if (N % 2 == 0) {
			cout << N << endl;
			break;
		}
		else {
			N += N;
		}
	}



}




