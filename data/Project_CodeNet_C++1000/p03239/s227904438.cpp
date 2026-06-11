#include<bits/stdc++.h>
using namespace std;

int d[1000001];
int main()
{
int n,t,an=INT_MAX,c,x;
cin>>n>>t;
while(n--){cin>>c>>x;
	if(x<=t)an=min(an,c);}
	
	
	if(an==INT_MAX)puts("TLE");else
	cout<<an<<endl;

}

