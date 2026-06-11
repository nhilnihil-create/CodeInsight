#include<bits/stdc++.h>
#define int long long
#define REP(i,a,n) for(int i=a;i<(n);i++)
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,a[100001],ans=0,fushu=0,zero=0;
	cin>>n;
	REP(i,0,n){
		cin>>a[i];
		fushu+=a[i]<0;
		zero+=!a[i];
		a[i]=abs(a[i]);
		ans+=a[i];
	}
	sort(a,a+n);
	if(!zero&&fushu%2)ans-=2*a[0];
	cout<<ans<<endl;
    return 0;
}
