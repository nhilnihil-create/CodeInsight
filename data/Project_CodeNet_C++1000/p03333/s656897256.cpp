#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

bool f1(pair<int,int> p1, pair<int,int> p2){
	return p1.first>p2.first;
}

bool f2(pair<int,int> p1, pair<int,int> p2){
	return p1.second<p2.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin>>n;
	vector<pair<int,int> > vr(n+1),vl(n+1);
	int i,j;
	for(i=0;i<n;i++){
		cin>>vl[i].first>>vl[i].second;
		vr[i]=vl[i];
	}
	sort(vl.begin(), vl.end(), f1);
	sort(vr.begin(), vr.end(), f2);

	ll ans=0;

	for(i=0;i<n+1;i++){
		if(vl[i].first > vr[i].second)	ans+=2*(vl[i].first-vr[i].second);
		else	break;
	}

	cout<<ans<<endl;

	return 0;
}