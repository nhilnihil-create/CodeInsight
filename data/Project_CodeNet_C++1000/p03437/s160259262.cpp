#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	long long int X, Y;
	cin >> X;
	cin >> Y;
	if (X * Y <=1000000000000000000 &&X%Y!=0) {
		cout << X;

	}
	else {
		cout << "-1";
	}
}