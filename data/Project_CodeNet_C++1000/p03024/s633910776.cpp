#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int x=0,n=s.size();
	for(int i=0;i<n;i++)s[i]-'o'?x++:0;
	cout<<(15-x>7?"YES":"NO")<<endl;
}