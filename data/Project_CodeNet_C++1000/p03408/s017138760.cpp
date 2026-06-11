#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	map<string, int> value;
	string s[100];
	int strSize = 0;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		auto iter = value.find(str);
		if (iter != end(value)) {
			value[str]++;
		}
		else {
			value[str] = 1;
			s[strSize++] = str;
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string str;
		cin >> str;
		auto iter = value.find(str);
		if (iter != end(value)) value[str]--;
	}

	int max = 0;
	for (int i = 0; i < strSize; ++i) {
		if (max < value.at(s[i])) max = value.at(s[i]);
	}

	cout << max << endl;
}