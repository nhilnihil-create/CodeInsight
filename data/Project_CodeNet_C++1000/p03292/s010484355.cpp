#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int ans = max({ A,B,C }) - min({ A,B,C });

	cout << ans << endl;

}