#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int k=s.size()-8;
	for(int i=0;i<k;i++)
	    printf("%c",s[i]);
	printf("\n");
	return 0;
}