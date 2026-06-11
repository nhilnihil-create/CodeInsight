#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int num[3]={0},i;
	cin >> s;
	for(i=0;i<s.size();i++)
		num[s[i]-'a']++;
	i=min(num[0],min(num[1],num[2]));
	if(num[0]-i>1 || num[1]-i>1 || num[2]-i>1) puts("NO");
	else puts("YES");
}