#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int y = stoi(s.substr(0,2));
	int m = stoi(s.substr(2,2));
	if(m > 0 && m <= 12) {
		if(y > 0 && y <= 12) { 
			cout << "AMBIGUOUS" << endl;
			return 0;
		}
		cout << "YYMM" << endl;
	}
	else if (y > 0 && y <= 12) cout << "MMYY" << endl;
	else cout << "NA" << endl;
	return 0;
}