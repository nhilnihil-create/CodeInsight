#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k; 
	int p=1;
	for(int i=1;i<=n;i++){
		if(k>p)p*=2;
		else p+=k;
	}
	cout<<p<<endl;
    return 0;
}
