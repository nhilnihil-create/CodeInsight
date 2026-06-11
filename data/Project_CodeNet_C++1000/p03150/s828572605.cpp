#include<bits/stdc++.h>
#define mkp make_pair
#define all(a) a.begin(),a.end() 
using namespace std;
typedef long long ll;
typedef map<ll,ll>::iterator itll;
typedef pair<ll,ll> P; 
int main()
{
	string s;
	cin>>s; 
	for(int pos = 0;pos<s.size();pos++)
	{
		for(int len = 0;len<=s.size();len++)
		{
			string k = s;
			k.erase(pos,len);
			if(k == "keyence")
			{
				cout<<"YES\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}