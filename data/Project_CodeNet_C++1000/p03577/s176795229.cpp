#include"bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main() {
	string s;
	cin >> s;
	int num = 8;
	while (num--) {
		s.pop_back();
	}
	cout << s << endl;
	return 0;
}
