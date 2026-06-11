#include <iostream>
#include <string>
using namespace std;
int main() {

	string S;
	cin >> S;
	S[3] = S[3] + 1;
	cout << S << endl;

	return 0;
}