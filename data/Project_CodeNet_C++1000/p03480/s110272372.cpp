#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int n=a.size();
	int k=n/2;
	char c=a[n-k-1];
	for(int i=k+1;i<=n;++i)
	{
		//cout<<c<<" "<<a[n-i]<<" "<<a[i-1]<<endl;
		if(a[n-i]!=a[i-1]||a[n-i]!=c)
              break;
		else ++k;
	}
	cout<<k<<endl;
	return 0; 
 } 