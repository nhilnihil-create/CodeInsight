#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pb push_back

int main()
{
	string s;
	cin>>s;
	
	int k;
	int n  = s.length();
	cin>>k;
	set<string>arr;
	for(int i=0;i<s.length();i++)
	{
		string x="";
		for(int j=i;j<min(n,(i+k));j++)
				{
					x=x+s[j];
					arr.insert(x);
				}
	}
auto it = arr.begin();
for(int i=0;i<k-1;i++)
	it++;
cout<<*it<<"\n";
}
