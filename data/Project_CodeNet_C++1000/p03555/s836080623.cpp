#include<iostream>
using namespace std;
#include<string>
#include<strstream>
#include<sstream>
#include<algorithm>
#include<math.h>
int main()
{
	string s, m;
	cin >> s >> m;
	reverse(s.begin(), s.end());
	if (s == m)
		cout << "YES";
	else
		cout << "NO";

}
