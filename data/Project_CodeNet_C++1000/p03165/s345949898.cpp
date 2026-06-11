#include <iostream>
#include <string>
using namespace std;

struct element {
	int size;
	int addres[2];
};

const int MAXN = 3 * 1E3 + 2;
element answer[MAXN][MAXN];

int main () {
	// input
	string s;
	string t;
	cin >> s >> t;
	int ss = s.size(), ts = t.size(); 
	// make the ones that needs to be 0, 0
	for (int i = 0; i <= ss; i ++) {
		answer[i][0].size = 0;
		answer[i][0].addres[0] = 0;
		answer[i][0].addres[1] = 0;
	}
	for (int i = 0; i <= ts; i ++) {
		answer[0][i].size = 0;
		answer[0][i].addres[0] = 0;
		answer[0][i].addres[1] = 0;
	}
	
	
	
	// final calculation	
	for (register int i = 0; i < ss; i ++) {
		for (register int j = 0; j < ts; j ++) {
			// if equal
			if (s[i] == t[j]) {
				answer[i + 1][j + 1].size = answer[i][j].size + 1;
			//	cout << "( " << answer[i + 1][j + 1].size << ", ";
				answer[i + 1][j + 1].addres[0] = -1;
				answer[i + 1][j + 1].addres[1] = -1;
			//	cout << -1 << " " << -1 << ")" << "   ";
				continue;
			}
			// if not equal
			if (answer[i][j + 1].size > answer[i + 1][j].size) {
				answer[i + 1][j + 1].addres[0] = -1;
				answer[i + 1][j + 1].addres[1] = 0;
				answer[i + 1][j + 1].size = answer[i][j + 1].size;
			//	cout << "( " << answer[i + 1][j + 1].size << ", ";
			//	cout << -1 << " " << 0 << ")" << "   ";
				continue;
			}
			answer[i + 1][j + 1].addres[0] = 0;
			answer[i + 1][j + 1].addres[1] = -1;
			answer[i + 1][j + 1].size = answer[i + 1][j].size;
		//	cout << "( " << answer[i + 1][j + 1].size << ", ";
			//	cout << 0 << " " << -1 << ")" << "   ";
		}
	//	cout << endl;
	}
	// output
	string ans = "";
	ss --;
	ts --;
	while (ss >= 0 && ts >= 0) {
		if (answer[ss + 1][ts + 1].addres[0] == -1 && answer[ss + 1][ts + 1].addres[1] == -1)
			ans += s[ss];
		//cout << "ss is " << ss << endl;
		//cout << "ts is " << ts << endl;
		//cout << "ss will get " << answer[ss + 1][ts + 1].addres[0] << endl;
		//cout << "ts will get " << answer[ss + 1][ts + 1].addres[1] << endl;
		int changess = answer[ss + 1][ts + 1].addres[0];
		int changets = answer[ss + 1][ts + 1].addres[1];
		ss += changess;
		ts += changets;
		//cout << "ss is " << ss << endl;
		//cout << "ts is " << ts << endl << "______________________" << endl;
	}
	if (ans.size() == 0) {
		cout << ' ' << endl;
		return 0;
	}
	for (int i = ans.size() - 1; i >= 0; i --)
		cout << ans[i];
	return 0;
}
