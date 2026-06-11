#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;
typedef long long ll;

int search(string S, string T) 
{
	int Tz = T.size();
	//後ろから順に、Tの入る場所を探す。
	for (int s = S.size() - 1; s >= 0; --s) {
		if (s - Tz + 1 < 0) return -1;

		string sub = S.substr(s - Tz + 1, Tz);
		for (int t = 0; t < Tz; ++t) {

			if (sub[t] == '?'
				|| sub[t] == T[t]) {
				if (t == Tz - 1) return s - Tz + 1;
			}
			else {
				break;
			}
		}
	}
	return -1;
}

int main()
{
	string S, T; cin >> S >> T;
	int t = search(S, T);
	if (t == -1) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	for (int s = 0; s < S.size(); ++s) {
		if (s >= t 
			&& s < t + T.size()) {
			cout << T[s - t];
		}
		else if (S[s] == '?') {
			cout << 'a';
		}
		else {
			cout << S[s];
		}
	}
	cout << endl;
	return 0;
}
