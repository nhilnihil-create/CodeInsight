#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m;
	cin>>n>>m;
	map<ll,int>rel;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		rel[num]++;
	}
	for(int i=0; i<m; i++){
		int num1,num2;
		cin>>num1>>num2;
		rel[num2]+=num1;
	}
	vector<pair<int,int> >store;
	for(auto var : rel){
		store.push_back(make_pair(var.first,var.second));
	}
	reverse(store.begin(),store.end());
	ll sum=0;
	int rem=n;
	int i=0;
	while(rem)
	{
		ll var=store[i].first;
		int cnt=store[i].second;
		sum=sum+var*min(cnt,rem);
		rem-=min(cnt,rem);
		i++;
	}
	cout<<sum;
	return 0;
	
}