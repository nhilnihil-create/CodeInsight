#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	string N;
	int A, B;
	cin >> N >> A >> B;
	int rec = 0;
	int ans = 0;
	for (int i = 1; i <= atoi(N.c_str()); i++) {
		for (int j = 0; j < to_string(i).length(); j++) {
			rec += to_string(i)[j] - '0';
		}
		if (rec >= A && rec <= B) {
			ans += i;
		}
		rec = 0;
	}
	cout << ans << endl;
	return 0;
}