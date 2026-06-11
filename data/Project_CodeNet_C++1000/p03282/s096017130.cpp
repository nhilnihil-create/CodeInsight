#include <bits/stdc++.h>
using namespace std;

int main() {
	string aa;
	cin >> aa;
	char s = '1';
	int k,n=0;
	cin >> k;
	for(int i=0;i<aa.size();i++)
	{
		if(aa.at(i) != '1')
		{
			s = aa.at(i);
			n = i+1;
			break;
		}
	}
	if(k < n)
	{
		s = '1';
	}
    cout << s << endl;
	return 0;
}
