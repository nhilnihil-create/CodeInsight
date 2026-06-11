#include <iostream>
#include <cstdio>
using namespace std;

int n, a;
int main() {
	cin >> n >> a;
	cout << (n%500 > a ? "No" : "Yes");
	return 0;
}
