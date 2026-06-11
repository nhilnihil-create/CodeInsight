#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	string t=s;
	for(int i=0;i<t.size();i++)
	{
		for(int j=0;j<t.size();j++)
		{
			t.erase(i,j);
			if(t.compare("keyence")==0){
				cout<<"YES\n";
				return 0;
			}
			t=s;
		}
	}
	cout<<"NO\n";
	return 0;
}