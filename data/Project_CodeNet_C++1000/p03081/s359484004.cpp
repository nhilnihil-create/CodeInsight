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


	int left = -1;
	int right = n;
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if ('R' == Move(mid, n, q, s, t, d)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	int from_right = right;

	left = -1;
	right = n;
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if ('L' == Move(mid, n, q, s, t, d)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	int from_left = left;

	int alive = from_right - from_left - 1;
	alive = max(alive, 0);
	//cout <<  from_right << " " << from_left << " ";
	cout << alive << endl;


	return 0;
}