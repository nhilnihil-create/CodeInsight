#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,c;
	cin>>a>>b>>c;
	if ((a<c&&c<b)||(b<c&&c<a))
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
