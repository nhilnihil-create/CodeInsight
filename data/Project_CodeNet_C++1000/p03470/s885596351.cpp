#include<iostream>
using namespace std;
#include<string>
#include<strstream>
#include<sstream>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<set>
int main()
{
	set<int>s;
	int n,x; cin >> n;
	while (n--)
	{
		cin >> x;
		s.insert(x);
	}
	cout << s.size();
	
}