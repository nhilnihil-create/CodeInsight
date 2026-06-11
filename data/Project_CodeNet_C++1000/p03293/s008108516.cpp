#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
	string msg = "No";
	cin >> s >> t;
 
	for (int i = 0; i < s.size(); i++) {
		s = s[s.size() - 1] + s.substr(0, s.size()-1);
		if (s == t) {
			msg = "Yes";
			break;
		}
	}
 
	cout << msg << endl;
}