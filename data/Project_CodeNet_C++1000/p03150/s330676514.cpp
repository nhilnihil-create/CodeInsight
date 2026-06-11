#include<bits/stdc++.h>
using namespace std;
int main()
{
	string S;
	string K="keyence";
	cin>>S;
	for(int i=0;i<7;i++)
		if(S.substr(0,i)==K.substr(0,i)&&S.substr(S.length()-7+i)==K.substr(i))
		{
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}