#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> streak;
int input[100 + 10];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> input[i];

	int length = 1;
	for (int i = 1; i < N; i++) {
		if (input[i] == input[i - 1])length++;
		else {
			streak.push_back(length);
			length = 1;
		}
	}
	streak.push_back(length);
	length = 1;

	int ans = 0;
	for (int i = 0; i < streak.size(); i++) {
		ans += streak[i] / 2;
	}
	cout << ans << endl;
	return 0;
}