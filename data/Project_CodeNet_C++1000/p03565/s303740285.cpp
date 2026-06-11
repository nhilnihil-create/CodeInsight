#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_dubious_document2(void) {
	string s, t;
	cin >> s >> t;

	int s_size = s.size();
	int t_size = t.size();
	vector<string> s_que;
	int diff = s_size - t_size;
	for (int i = 0; i <= diff; i++) {
		//cout << i << endl;
		string s_ans = s.substr(0, i) + t + s.substr(i + t_size, s_size - t_size - i);
		//cout << s_ans << endl;
		bool match_judge = true;
		for (int j = 0; j < t_size; j++) {
			if (s[i + j] == '?') {
				s_ans[i + j] = t[j];
				continue;
			}
			if (s[i + j] != t[j]) {
				match_judge = false;
				break;
			}
		}

		if (match_judge) {
			//cout << s_ans << endl;
			s_que.push_back(s_ans);
		}

	}

	if (s_que.size() == 0) {
		cout << "UNRESTORABLE" << endl;
		return;
	}

	sort(s_que.begin(), s_que.end());
	for (int i = 0; i < s_que[0].size(); i++) {
		if (s_que[0][i] == '?')s_que[0][i] = 'a';
	}

	cout << s_que[0] << endl;
}

int main()
{
    c_dubious_document2();
    return 0;
}