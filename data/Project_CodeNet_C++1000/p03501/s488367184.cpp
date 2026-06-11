#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	cin>>n>>a>>b;
	if(n*a<b)
		cout<<n*a<<endl;
	else
		cout<<b<<endl;
	return 0;
}