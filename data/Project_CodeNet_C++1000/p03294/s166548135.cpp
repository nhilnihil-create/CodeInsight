#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,x;
	cin>>n;
	int sum=-n;
	while(n--){
		cin>>x;
		sum+=x;
	}
	cout<<sum<<endl;
    return 0;
}
