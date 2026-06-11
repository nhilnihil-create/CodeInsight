#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s; cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			string tmp = s.substr(i, s.size() - j);
			bool flag = true;
			for (int tmpI = 0; tmpI < tmp.size(); tmpI++) {
				if (tmp[tmpI] != 'A' && tmp[tmpI] != 'C' && tmp[tmpI] != 'G' && tmp[tmpI] != 'T') {
					flag = false;
				}
			}
			if (flag) {
				if (tmp.size() > ans) {
					ans = tmp.size();
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}