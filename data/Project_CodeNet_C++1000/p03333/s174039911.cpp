#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;

int main()
{
	int n;
	cin>>n;
	ll l[100000], r[100000];
	multiset<P> ls, rs;
	for(int i=0; i<n; i++){
		cin>>l[i]>>r[i];
		ls.insert(P(l[i], r[i]));
		rs.insert(P(r[i], l[i]));
	}
	ll x=0, ans=0;
	for(int i=0; i<n; i++){
		if(i%2==0){
			auto itr1=ls.end();
			itr1--;
			ll d1=max((*itr1).first-x, 0ll);
			ans+=d1;
			x+=d1;
			ll l1=(*itr1).first, r1=(*itr1).second;
			ls.erase(itr1);
			auto itr=rs.lower_bound(P(r1, l1));
			rs.erase(itr);
		}else{
			auto itr2=rs.begin();
			ll d2=max(x-(*itr2).first, 0ll);
			ans+=d2;
			x-=d2;
			ll l1=(*itr2).second, r1=(*itr2).first;
			rs.erase(itr2);
			auto itr=ls.lower_bound(P(l1, r1));
			ls.erase(itr);
		}
	}
	ans+=abs(x);
	for(int i=0; i<n; i++){
		ls.insert(P(l[i], r[i]));
		rs.insert(P(r[i], l[i]));
	}
	x=0;
	ll ans2=0;
	for(int i=0; i<n; i++){
		if(i%2==1){
			auto itr1=ls.end();
			itr1--;
			ll d1=max((*itr1).first-x, 0ll);
			ans2+=d1;
			x+=d1;
			ll l1=(*itr1).first, r1=(*itr1).second;
			ls.erase(itr1);
			auto itr=rs.lower_bound(P(r1, l1));
			rs.erase(itr);
		}else{
			auto itr2=rs.begin();
			ll d2=max(x-(*itr2).first, 0ll);
			ans2+=d2;
			x-=d2;
			ll l1=(*itr2).second, r1=(*itr2).first;
			rs.erase(itr2);
			auto itr=ls.lower_bound(P(l1, r1));
			ls.erase(itr);
		}
	}
  	ans2+=abs(x);
	cout<<max(ans, ans2)<<endl;
	return 0;
}