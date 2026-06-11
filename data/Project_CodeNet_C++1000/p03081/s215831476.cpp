#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

//#define FILE_INPUT
//#define DEBUG_MODE

char Move(int position, int n, int q, string s, vector<char> &t, vector<char> &d)
{
	for (int i = 0; i < q; ++i) {
		if (s[position] == t[i]) {
			if (d[i] == 'L') {
				position--;
			}
			else {
				position++;
			}
		}
		if (0 > position) {
			return 'L';
		}
		if (n <= position) {
			return 'R';
		}
	}
	return ' ';
}

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


	int left_limit = n;		// from right
	int left = 0;
	int right = n - 1;
	if ('R' == Move(left, n, q, s, t, d)) {
		left_limit = left;
	}
	else if ('R' != Move(right, n, q, s, t, d)) {
		left_limit = n;
	}
	else {
		for (;;) {
			int mid = (left + right) / 2;
			if ('R' == Move(mid, n, q, s, t, d)) {
				if (left == mid) {
					left_limit = left;
					break;
				}
				right = mid;
			}
			else {
				if (left == mid) {
					left_limit = right;
					break;
				}
				left = mid;
			}
		}
	}



	int right_limit = -1;	// from left
	left = 0;
	right = n - 1;
	if ('L' == Move(right, n, q, s, t, d)) {
		right_limit = right;
	}
	else if ('L' != Move(left, n, q, s, t, d)) {
		right_limit = -1;
	}
	else {
		for (;;) {
			int mid = (left + right) / 2;
			if ('L' == Move(mid, n, q, s, t, d)) {
				if (left == mid) {
					right_limit = left;
					break;
				}
				left = mid;
			}
			else {
				right = mid;
			}
		}
	}

	int alive = left_limit - right_limit - 1;
	alive = max(alive, 0);
	//cout << left_limit << " " << right_limit << " ";
	cout << alive << endl;


	return 0;
}