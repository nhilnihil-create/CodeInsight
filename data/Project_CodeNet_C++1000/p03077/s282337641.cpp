#include<bits/stdc++.h>
#define int long long
#define REP(i,a,n) for(int i=a;i<(n);i++)
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int a[5],n,mini=(int)(1E16);
	cin>>n;
	REP(i,0,5){
		cin>>a[i];
		mini=min(mini,a[i]);
	}
	int ans;
	if(mini<n){
		ans=4+n/mini;
		if(n%mini)ans++;
	}else ans=5;
	cout<<ans<<endl;
    return 0;
}
