#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int n;
	double a,sum=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>s;
		if(s=="JPY")sum+=a;
		else sum+=a*380000.0;
	}
	cout<<setprecision(15)<<sum<<endl;
	return 0;
}
