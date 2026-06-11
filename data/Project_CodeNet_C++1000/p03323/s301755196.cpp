#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	cout << (a<9 && b<9 ? "Yay!" : ":(");
	return 0;
}
