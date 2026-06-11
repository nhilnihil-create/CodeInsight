#include <bits/stdc++.h>
using namespace std;

int main()
{
	int br=0;
	string s;
	cin >> s;
	if(s[0]=='2') br++;
	if(s[1]=='2') br++;
	if(s[2]=='2') br++;
	if(s[3]=='2') br++;

	printf("%d", br);

    return 0;
}
