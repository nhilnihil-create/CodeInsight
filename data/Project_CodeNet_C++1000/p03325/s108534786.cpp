#include<bits/stdc++.h>
#define int long long
using namespace std;
int two(int x)
{
	int sum=0;
	while(1){
		if(x%2==0)sum++;
		else break;
		x/=2;
	}
	return sum;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int ans=0;
	int n,x;
	cin>>n;
	while(n--){
		cin>>x;
		ans+=two(x);
	}
	cout<<ans<<endl;
    return 0;
}
