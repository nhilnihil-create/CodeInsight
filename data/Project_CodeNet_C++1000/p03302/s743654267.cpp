#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
int a,b=1;
signed main()
{
	cin>>a>>b;
	if(a*b==15){
		cout<<'*';
	}elif(a+b==15){
		cout<<'+';
	}else{
		cout<<'x';
	}
}