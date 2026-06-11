#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string s;
	cin>>s;
	int one=0;
	int zero=0;
	for(char c : s)
	{
		if(c=='0') zero++;
		else one++;
	}
	cout<<min(zero,one)*2<<endl;
	return 0;
}
