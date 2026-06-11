#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string y = s.substr(0, 4);
	string m = s.substr(5, 2);
	string d = s.substr(8, 2);

	if (stoi(y) <= 2019 && stoi(m) <= 4 &&  stoi(d) <= 30)
		cout << "Heisei\n";
	else
		cout << "TBD\n";
}

