#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int a,b,k;
	set<int> s;
	cin>>a>>b>>k;
	int c,d;
	c=a;
	d=b;
	for (int i = 0; i <k ; ++i)
		{
			if(a<=d)
			s.insert(a++);
			if(b>=c)
			s.insert(b--);
		}	

	for (auto e:s)
	{
		cout<<e<<endl;
	}
   return 0;
}
