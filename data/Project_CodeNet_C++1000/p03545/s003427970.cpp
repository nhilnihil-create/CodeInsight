#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int A, B, C, D;
	string s, t;
	cin >> s;
	t = s[0];
	A = stoi(t);
	t = s[1];
	B = stoi(t);
	t = s[2];
	C = stoi(t);
	t = s[3];
	D = stoi(t);

	const int ADD = 0;
	const int SUB = 1;

	int tp = A;
	bool find = false;
	rep(i, 2)
	{
		rep(j, 2)
		{
			rep(k, 2)
			{
				s = to_string(A);
				tp = A;
				if (i == ADD) {
					tp += B;
					s += "+" + to_string(B);
				}
				else {
					tp -= B;
					s += "-" + to_string(B);
				}

				if (j == ADD) {
					tp += C;
					s += "+" + to_string(C);
				}
				else {
					tp -= C;
					s += "-" + to_string(C);
				}

				if (k == ADD) {
					tp += D;
					s += "+" + to_string(D);
				} else {
					tp -= D;
					s += "-" + to_string(D);
				}

				if (tp == 7) {
					find = true;
					s += "=7";
					cout << s << endl;
				}

				if (find) break;
			}
			if (find) break;
		}
		if (find) break;
	}

	return 0;
}