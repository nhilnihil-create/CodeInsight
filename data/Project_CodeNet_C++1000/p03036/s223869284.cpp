#include<bits/stdc++.h>
#define ll long long int
#define N 100010
using namespace std;
int main() 
{
	int r,d,x;
	cin>>r>>d>>x;
	vector<ll> n(10);
	n[0]=x;
	for(int i=1;i<=10;i++)
	{
		n[i]=r*n[i-1]-d;
		cout<<n[i]<<endl;
	}
	return 0;
}
