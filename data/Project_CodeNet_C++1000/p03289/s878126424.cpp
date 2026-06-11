#include<bits/stdc++.h>
using namespace std;
void AC(){cout<<"AC\n";exit(0);}
void WA(){cout<<"WA\n";exit(0);}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin>>s;
	if(s[0]!='A'||s[1]=='C'||s[s.size()-1]=='C')WA();
	int C=0;
	for(int i=1;i<s.size();i++)
	{
	if(isupper(s[i])&&s[i]!='C')WA();
	if(i!=1&&s[i]=='C')C++;
	if(C>1)WA();
	}
	if(!C)WA();
	AC();
    return 0;
}
