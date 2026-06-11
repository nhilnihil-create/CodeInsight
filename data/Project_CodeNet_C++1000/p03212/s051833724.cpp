#include <iostream>
#include <string>
#include <set>

using namespace std;

long long n;
set<long long> st;

void dfs(string s, long long a);
bool check(string s);

int main()
{
	cin >> n;

	dfs("3", 3);
	dfs("5", 5);
	dfs("7", 7);

	cout << st.size() << endl;

	return 0;
}

void dfs(string s, long long a)
{
	if (check(s)) {
		st.insert(a);
	}

	if (a * 10 + 3 <= n) {
		dfs(s + "3", a * 10 + 3);
	}

	if (a * 10 + 5 <= n) {
		dfs(s + "5", a * 10 + 5);
	}

	if (a * 10 + 7 <= n) {
		dfs(s + "7", a * 10 + 7);
	}
}

bool check(string s)
{
	bool a[3] = {};

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '3':
			a[0] = true;
			break;
		case '5':
			a[1] = true;
			break;
		case '7':
			a[2] = true;
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (!a[i]) {
			return false;
		}
	}
	return true;
}