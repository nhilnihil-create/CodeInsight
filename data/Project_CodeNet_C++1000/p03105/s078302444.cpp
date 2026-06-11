#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c;
	cin >> a >> b >> c;
	cout << min(c,b/a);
	return 0;
}