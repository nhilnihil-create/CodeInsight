#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string isLessThan(string s, string t)	{
	if (s.length() < t.length())	{
		for (int i = 0; i < s.length(); i++)	{
			if (s[i] < t[i])	{
				return "Yes";
			}
			else if (s[i] > t[i])	{
				return "No";
			}
		}
		return "Yes";
	}
	else if (s.length() >= t.length())	{
		bool valid = false;
		for (int i = 0; i < min(s.length(), t.length()); i--)	{
			if (s[i] > t[i]) return "No";
			else if (s[i] < t[i]) valid = true;
		}
		if (valid) return "Yes";
		return "No";
	}
	return "Noice";
}


int main()	{
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<char>());
	cout << isLessThan(s, t) << endl;
	return 0;
}
