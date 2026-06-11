#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;



int main() {
	string n;
	cin >> n;
	int ans = 700;

	for (int i = 0; i < 3; i++) {
		if (n[i] == 'o') {
			ans += 100;
		}
		else {
			ans += 0;
		}
	}
	cout << ans;
}