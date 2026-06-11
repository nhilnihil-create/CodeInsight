#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	int x = A + B;
	int y = A - B;
	int z = A * B;
	cout << max({ x, y, z }) << endl;
}