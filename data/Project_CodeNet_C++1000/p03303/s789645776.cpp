#include<bits/stdc++.h>
using namespace std;
string a;
long long b;
int main()
{
	cin>>a>>b;
	for(int s=0;s<a.size();s+=b)
	{
		cout<<a[s];
	}
	puts("");
}