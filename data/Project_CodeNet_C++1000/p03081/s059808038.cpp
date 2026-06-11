#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

//#define FILE_INPUT
//#define DEBUG_MODE

int main()
{
#ifdef FILE_INPUT
	ifstream in("test3.txt");
	cin.rdbuf(in.rdbuf());
#endif	/* FILE_INPUT */  
	int n, q;

	cin >> n >> q;
	string s;
	cin >> s;
	vector<char> t(q);
	vector<char> d(q);
	for (int i = 0; i < q; ++i) {
		cin >> t[i] >> d[i];
	}

	reverse(t.begin(), t.end());
	reverse(d.begin(), d.end());

	int right_limit = -1;	// from left
	int left_limit = n;		// from right
	for (int i = 0; i < (int)t.size(); ++i) {
		if (right_limit >= n - 1) {
			break;
		}
		if (left_limit < 0) {
			break;
		}
		if (left_limit <=  right_limit) {
			break;
		}
		if (d[i] == 'L') {
			if (s[right_limit + 1] == t[i]) {
				++right_limit;
			}
			if (left_limit < n && s[left_limit] == t[i]) {
				++left_limit;
			}
		}
		if (d[i] == 'R') {
			if (right_limit >= 0 && s[right_limit] == t[i]) {
				--right_limit;
			}
			if (s[left_limit - 1] == t[i]) {
				--left_limit;
			}
		}
	}

	int alive = left_limit - right_limit - 1;
	alive = max(alive, 0);
	cout << alive << endl;

	return 0;
}