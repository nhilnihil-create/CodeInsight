#include<iostream>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
	ios;
	int n,m;
	cin>>n>>m;
	n%=500;
	if(m>=n)cout<<"Yes\n";
	else cout<<"No\n";
} 