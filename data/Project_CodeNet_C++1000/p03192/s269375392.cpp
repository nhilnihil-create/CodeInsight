#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int cnt=0;	
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='2')cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}