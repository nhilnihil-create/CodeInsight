#include<bits/stdc++.h>
#define ft(i,l,r) for(register int i=l;i<=r;i++)
#define fd(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
int n;
int main()
{
	cin>>n;
	if(n%111==0) cout<<n;
	else cout<<n+(111-n%111);
	return 0;
}