#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> xa, ya;
int d[100009], td[100009];

bool ps(vector<int> a)
{
	int s = 0;
	for (int i = 0; i < a.size(); i++)
		s += a[i];
	if (s % 2 == 1) return false;
	for (int i = 0; i <= s; i++) {
		d[i] = td[i] = 0;
	}
	d[0] = 1;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j <= s; j++)
			if (d[j] == 1) {
				if (0 <= j - a[i] && j - a[i] <= s) td[j - a[i]] = 1;
				if (0 <= j + a[i] && j + a[i] <= s) td[j + a[i]] = 1;
			}
		for (int j = 0; j <= s; j++) {
			d[j] = td[j]; td[j] = 0;
		}
	}
	if (d[0] == 1)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s; s += "T";
	int tx, ty; cin >> tx >> ty;
	bool f = true; int r = 0, c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (f && s[i] == 'F') {
			tx--;
			continue;
		}
		else
			f = false;
		if (s[i] == 'T') {
			if (c > 0) {
				if (!r) xa.push_back(c);
				else ya.push_back(c);
			}
			c = 0; r = (r + 1) % 2;
		}
		else
			c++;
	}
	xa.push_back(abs(tx)); ya.push_back(abs(ty));
	if (ps(xa) && ps(ya)) cout << "Yes" << '\n';
	else cout << "No" << '\n';
	return 0;
}