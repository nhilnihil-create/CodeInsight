#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	s[k-1]+='a';
	s[k-1]-='A';
	cout<<s;
	return 0;
}