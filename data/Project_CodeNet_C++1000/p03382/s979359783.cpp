#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;++i){
	       cin>>v[i].first;
	       v[i].second=i;
	}
	sort(v.begin(), v.end());
	vector<int> ans(n);
	int mx=v[0].first;
	auto dist=[](int n, int x){
		if(n%2==0) return abs(n/2-x);
		else return min(abs(n/2-x), abs((n+1)/2-x));
	};
	for(int i=0;i<n-1;++i){
		int x=v[i].first;
		if(dist(v.back().first,x) < dist(v.back().first,mx) ) mx=x;
	}
	cout<<v.back().first<<' '<<mx<<endl;
}
