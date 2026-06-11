#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string st;
string t;
vector<string> ss;

int main() {

	cin >> st >> t;
	
	string ans;
	ans.resize(st.length());
	bool flag;

	for (int i = 0; i < (st.length() - t.length())+1; i++) {
		for (int j = 0; j < t.length(); j++) {
			if (st[i + j] == t[j] || st[i + j] == '?') {
				ans[i + j] = t[j];
				flag = true;
			}
			else{
				for (int l = 0; l < ans.length(); l++) {
					ans[l] = 0;
				}
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int k = 0; k < st.length(); k++) {
				if (st[k] == '?' && ans[k] == 0)
					ans[k] = 'a';
			}
			for (int k = 0; k < st.length(); k++) {
				if (ans[k] == 0)
					ans[k] = st[k];
			}
			ss.push_back(ans);
			for (int k = 0; k < ans.length(); k++)
				ans[k] = 0;
		}
	}

	sort(ss.begin(), ss.end());

	if (ss.size()==0)
		cout << "UNRESTORABLE" << endl;
	else
		cout << ss[0] << endl;


}