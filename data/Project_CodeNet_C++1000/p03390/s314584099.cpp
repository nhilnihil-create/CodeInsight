#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll q,a,b,cnt,p,l;
int main()
{
	cin>>q;
	while(q--){
		cin>>a>>b;
		p=a*b;
		l=sqrt(p);
		if(l*(l+1)<p) cnt=2*(l-1)+1;
		else cnt=2*(l-1);
		if(l*l==p&&a!=b) cnt--;
		if(a*b==4) cnt=1;
		cout<<cnt<<endl;
	}
}