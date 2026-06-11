#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A == B) cout << C << endl;
	else cout << (A == C ? B : A) << endl;
}