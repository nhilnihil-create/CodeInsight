
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	string s;
	cin >> s;

	string ans;
	set<char> charSet;
	for (int i = 0; i <s.length();i++) {
		string tmp = s.substr(0, i);
		for (int j = 1; j < 26;j++) {
			if (s[i] + j > 'z') {
				break;
				
			}

			if (charSet.find(s[i] + j) == charSet.end()) {
				tmp += s[i] + j;
				
				ans = tmp;
				break;
			}
		}
		charSet.insert(s[i]);
		
	}

	if (charSet.size() < 26) {
		for (int i = 0;i < 26;i++) {
			if (charSet.find('a' + i) == charSet.end()) {
				ans = s;
				ans += 'a' + i;
				break;
			}
		}
	}
	
	if (ans.length() == 0) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}

