#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,n;	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	ll ans=0;
	for(i=0;i<n+1;i++){
		if(a[i] > b[i])	ans+=2*(a[i]-b[i]);
		else	break;
	}

	cout<<ans<<endl;

	return 0;
}