#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	long long int N;
	cin >> N;
	long long int Li = 2;
	long long int Li1 = 1;
	long long int Li2 = Li1 + Li;
	for (int i = 0; i < N - 2; i++) {
		Li = Li1;
		Li1 = Li2;
		Li2 = Li1 + Li;
	}
	if (N == 1) {
		cout << Li1 << endl;
	}
	else if (N == 2) {
		cout << Li2 << endl;
	}
	else { 
		cout << Li2 << endl; 
	}
	return 0;
}