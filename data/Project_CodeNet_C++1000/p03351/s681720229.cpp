#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c, d, e;
	cin>> a>>b>>c>>d;
	e = abs(a-b);
	b = abs(b-c);
	c = abs(a - c);

	if(e<=d && b<=d || c<=d){
		cout<<"Yes\n";
	}
	else
		cout<<"No\n";

		return 0;
}
