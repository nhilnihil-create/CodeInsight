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

	int N;
	cin >> N;

	if (1 <= N && N <= 999) {
		cout << "ABC" << endl;
	}
	else{
		cout << "ABD" << endl;
	}

	return 0;
}
