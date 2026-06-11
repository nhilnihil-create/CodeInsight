#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int long long 
const ll mod = 998244353;
int n,l[100000+5],r[100000+5];
multiset<pair<int,int> > ls,rs;

ll calc(int& curp,int l,int r){
	int temp=curp;
	if(curp>=r){curp=r;return -r+temp;}
	if(curp<=l){curp=l;return l-temp;}
	return 0;
}
main() {
	///freopen("input","r",stdin);
	
	cin>>n;
	int cnt1=0,cnt2=0;
	for(int  i=0;i<n;i++){cin>>l[i]>>r[i];}
	ll total =0;
	ll ans =0,curp = 0;
	for(int i=0;i<n;i++){ls.insert({-l[i],-r[i]});rs.insert({r[i],l[i]});}
	for(int i=0;!ls.empty()||!rs.empty();i++){
		if(i%2){
			pair<int,int>x=*ls.begin();
			ans+=calc(curp,-x.first,-x.second);
			ls.erase(ls.find(x));
			rs.erase(rs.find({-x.second,-x.first}));
		}
		else{
			pair<int,int>x=*rs.begin();
			ans+=calc(curp,x.second,x.first);
			rs.erase(rs.find(x));
			ls.erase(ls.find({-x.second,-x.first}));
		}
	}
	total=ans+abs(curp);
	//cout<<ans<<endl;
	ans =0,curp = 0;
	for(int i=0;i<n;i++){ ls.insert({-l[i],-r[i]});rs.insert({r[i],l[i]});}
	for(int i=0;!ls.empty()||!rs.empty();i++){
		if(i%2==0){
			pair<int,int>x=*ls.begin();
			//cout<<curp<<" "<<-x.first<<" "<<-x.second<<endl;
			ans+=calc(curp,-x.first,-x.second);
			ls.erase(ls.find(x));
			rs.erase(rs.find({-x.second,-x.first}));
		}
		else{
			pair<int,int>x=*rs.begin();
			//cout<<curp<<" "<<x.second<<" "<<x.first<<endl;
			ans+=calc(curp,x.second,x.first);
			rs.erase(rs.find(x));
			ls.erase(ls.find({-x.second,-x.first}));
		}
	}
	total=max(total,ans+abs(curp));

	cout<<total<<endl;



}
 
	
