#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	if(s[0] != 'A') cout << "WA" << endl;
	else {
		bool ok = false;
		for (int i = 2; i < s.size()-1; i++)
		{
			if(s[i] == 'C') ok = true;
		}
		if(!ok) cout << "WA" << endl;
		else {
			int c = 0;
			for (int j = 0; j < s.size(); j++)
			{
				if(s[j] >= 'A' && s[j] <= 'Z')
					c++;
			}
			if(c != 2) cout << "WA" << endl;
			else cout << "AC" << endl;
		}
	}
	return 0;
}
