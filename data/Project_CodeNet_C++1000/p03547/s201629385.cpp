#include<iostream>
using namespace std;

int main(void) {
	
	string X, Y;
	cin >> X >> Y;
	cout << ((X < Y) ? "<" : ((X > Y) ? ">" : "=")) << endl;
	return 0;

}
