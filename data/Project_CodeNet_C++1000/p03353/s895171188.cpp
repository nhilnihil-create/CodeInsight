#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N=5e3+5;
string s;
string a[N*5];
int n,k;

signed main()
{
	cin>>s>>k,n=0;
	for(register int i=0;i<(int)s.size();i++)	
		for(register int j=1;j<=5;j++)
			a[++n]=s.substr(i,j);
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	cout<<a[k]<<endl;
	return 0;
}