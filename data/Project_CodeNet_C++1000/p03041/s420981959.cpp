# include <iostream>
# include <string>
using namespace std;
int main()
{
	int n,k,m;
	cin>>n>>k;
	string s;
	cin>>s;
	m=int(s[k-1])+32;
	s[k-1]=(char)m;
	cout<<s;
	
}