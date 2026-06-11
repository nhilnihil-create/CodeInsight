#include <iostream>
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	int R = 0;
	for (char c : S) R += (c == 'R');
	cout << (R > N - R ? "Yes" : "No") << endl;
}