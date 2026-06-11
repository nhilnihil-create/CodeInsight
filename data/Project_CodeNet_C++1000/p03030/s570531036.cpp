#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	pair<pair<string,int>,int>a[101];
	cin>>n;
	for(int i=0;i<n;i++){
		a[i].second=i+1;
		cin>>a[i].first.first>>a[i].first.second;
		a[i].first.second*=-1;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)cout<<a[i].second<<endl;
    return 0;
}
