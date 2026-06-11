#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s; cin >> s; 
	int c = 0;
	for(int i = 0; i < s.size(); i ++)
		if(s[i] == 'x')
		    c ++;
	if(c <= 7) puts("YES");
	else puts("NO");
	return 0;
}