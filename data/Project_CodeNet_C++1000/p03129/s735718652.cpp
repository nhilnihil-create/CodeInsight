#include <iostream>
using namespace std;

int n, k;
int main() {
	cin>> n>> k;
	cout<< ((n+1)/2>=k ? "YES" : "NO");
	return 0;
}