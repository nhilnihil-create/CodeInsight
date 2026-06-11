#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

int main()
{

	ios_base:: sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;

	vector<int> a(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	int ans=1e9;
	int d=0;
	int cur=(a[n]+(a[n]%2))/2;
	for(int i=1; i<n; i++) {
		if(abs(a[i]-cur)<ans) {
			ans=abs(a[i]-cur);
			d=a[i];
		}
	}
	cout<<a[n]<<" "<<d<<endl;

	return 0;
}
