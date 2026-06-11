#include <bits/stdc++.h>
using namespace std;
#define ref(i,l,n) for(int i = l;i<=n;i++)

int main()
{
	int a,b;
	cin>>a>>b;
	if(a >= 13)
		cout<<b<<endl;
	else if(a >= 6 && a <= 12)
		cout<<b/2<<"\n";
	else cout<<0<<"\n";
	return 0;
}