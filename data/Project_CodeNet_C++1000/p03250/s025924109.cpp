#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int ans1 = 10 * A + B + C;
	int ans2 = A + 10 * B + C;
	int ans3 = A + B + 10 * C;

	cout << max({ ans1,ans2,ans3 }) << endl;
	
}