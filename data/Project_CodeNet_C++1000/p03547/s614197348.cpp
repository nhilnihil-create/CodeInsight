#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	char X,Y;
	cin >> X;
	cin >> Y;
	map<char,int> letr;
	if (X > Y) {
		cout << ">" << endl;
	}
	else if (X < Y) cout << "<" << endl;
	else cout << "=" << endl;

	return 0;
}