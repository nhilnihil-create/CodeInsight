#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
long long n,m,i,j,a[105],s;
int main()
{
	cin>>n>>m;
	rep(i,n)cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,n){
		m-=a[i];
		if(m>=0)s++;
	}
	if(m!=0)s=min(s,n-1);
	cout<<s<<endl;
	return 0;
}