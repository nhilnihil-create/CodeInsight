#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	string s;
	set<char>S;
	cin>>s;
	for(int i=0;i<3;i++)
	{
		S.insert(s[i]);
	}
	if(S.size()==3)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}