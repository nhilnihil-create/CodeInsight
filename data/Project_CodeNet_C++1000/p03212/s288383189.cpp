#include <bits/stdc++.h>

using namespace std;

vector < string> a;
void make753(int nn,string s) {
	if (nn < 0) {
		a.push_back(s);
		return;
	}

	s += '7';
	make753(nn - 1, s);
	s.pop_back();
	s += '5';
	make753(nn - 1, s);
	s.pop_back();
	s += '3';
	make753(nn - 1, s);
	s.pop_back();

}

int main() {

	int n;
	cin >> n;
	int nn;
	nn = (int)((double)log(n) / (double)log(10));

	string s;
	for (int i = 2; i <= nn; i++) {
		make753(i, s);
	}

	int counter = 0;
	for (int i = 0; i < a.size(); i++) {
		if (stoi(a[i]) > n) { continue; }
		vector<int> b(3,0);
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] == '7') { b[0] = 1; }
			if (a[i][j] == '5') { b[1] = 1; }
			if (a[i][j] == '3') { b[2] = 1; }
		}
		if (b[0] + b[1] + b[2] == 3) { counter++; }

//		cout << a[i] << endl;
	}
	cout << counter << endl;
	return 0;

}