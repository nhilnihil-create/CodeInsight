#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll X,Y;
	cin>>X>>Y;
	if(X%Y==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<X<<endl;
	}
	return 0;
}
