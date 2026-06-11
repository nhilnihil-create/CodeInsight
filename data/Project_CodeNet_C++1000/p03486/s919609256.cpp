#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s,t;
	cin >> s >> t;

	sort(s.begin(), s.end()); //sは昇順に
	sort(t.begin(), t.end(), greater<char>()); //tは降順に

	if (s < t) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}