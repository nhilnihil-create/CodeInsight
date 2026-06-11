#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(void) {
	string S;
	cin >> S;
	vector<int> count(3, 0);
	for (int i = 0; i < S.length(); i++) {
		count[S[i] - 'a']++;
	}
	if (*min_element(count.begin(), count.end()) + 1 >= *max_element(count.begin(), count.end())) cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}