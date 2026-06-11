#include <iostream>
using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A + B == C + D) cout << "Balanced" << endl;
	else cout << (A + B < C + D ? "Right" : "Left") << endl;
}
