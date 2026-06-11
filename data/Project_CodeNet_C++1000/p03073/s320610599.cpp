#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000000000000
#define mod 1000000007
#define ld long double
#define point complex<long double>
#define pi  acos(-1)
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
 
int main(){
	string s;
	cin>>s;
	ll resa=0;
	ll resb=0;
	for(int i=0;i<s.size();i++)
	{
		if(i%2==0)
		{
			if(s[i]=='0')resa++;
			else resb++;
		}
		else 
		{
			if(s[i]=='1')resa++;
			else resb++;
		}
	}
	cout<< min(s.size()-resa,s.size()-resb);
return 0;
}