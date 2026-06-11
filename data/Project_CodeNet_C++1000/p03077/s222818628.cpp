#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long  n,m=10000000000000000,a;
	cin>>n;
	for(int i=0;i<5;i++){cin>>a;m=min(a,m);}
	if(n<=m)cout<<5<<endl;
	else cout<<(5+(n-m)/m+(((n-m)%m)!=0))<<endl;
	

}

