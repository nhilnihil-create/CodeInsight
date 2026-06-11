#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;

bool cmp(string a,string b)
{
	int n=min(a.size(),b.size());
	rep(i,n)
	{
		if(a[i]!=b[i])
		{
			return a[i]<b[i];
		}
	}
	return a.size()<b.size();
}

int main()
{
	string s;
	cin >> s;
	if(s=="zyxwvutsrqponmlkjihgfedcba")
	{
		cout<<-1<<endl;
		return 0;
	}
	string alph = "abcdefghijklmnopqrstuvwxyz";
	if(s.size()==26)
	{
		char mi='z';
		for(int i=s.size()-1;i>=0;i--)
		{
			if(s[i-1]<s[i])
			{
				char minc='z';
				for(int j = i;j<s.size();j++)
				{
					//cout<<s[j]<<endl;
					if(s[j]>s[i-1])
					{
						minc=min(minc,s[j]);
					}
				}
				rep(j,i-1)cout<<s[j];
				cout<<minc<<endl;
				return 0;
			}	
		}
	}
	else
	{
		rep(i,s.size())
		{
			alph.erase(alph.begin()+alph.find(s[i]));
		}
		cout<<s<<alph[0]<<endl;
	}
	
	return 0;
}