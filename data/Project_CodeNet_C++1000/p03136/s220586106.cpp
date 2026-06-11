#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int max_len = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		max_len = max(max_len, l);
		total = total + l;
	}

	if ((total - max_len) > max_len) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
