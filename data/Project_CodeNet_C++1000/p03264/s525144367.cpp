#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
	if(n%2==0){
		cout<<n*n/4;
	}
	else{
		cout<<(n*n-1)/4;
	}
    return 0;
}
