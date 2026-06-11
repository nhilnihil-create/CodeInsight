#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	int a,b,q;
	cin>>a>>b>>q;
	vector<long long> s,t;
	for(int i=0;i<a;i++){
		long long hoge;
		cin>>hoge;
		s.push_back(hoge);
	}
	for(int i=0;i<b;i++){
		long long hoge;
		cin>>hoge;
		t.push_back(hoge);
	}
	long long nt[100000];
	long long ns[100000];
	for(int i=0;i<a;i++){
		int hoge=lower_bound(t.begin(),t.end(),s[i])-t.begin();
		if(hoge==a){
			nt[i]=abs(s[i]-t[a-1]);
		}else if(hoge==0){
			nt[i]=abs(s[i]-t[hoge]);
		}else{
			nt[i]=min(abs(s[i]-t[hoge]),abs(s[i]-t[hoge-1]));
		}
	}
	for(int i=0;i<b;i++){
		int hoge=lower_bound(s.begin(),s.end(),t[i])-s.begin();
		if(hoge==b){
			ns[i]=abs(t[i]-s[b-1]);
		}else if(hoge==0){
			ns[i]=abs(t[i]-s[hoge]);
		}else{
			ns[i]=min(abs(t[i]-s[hoge]),abs(t[i]-s[hoge-1]));
		}
	}
	for(int i=0;i<q;i++){
		long long ans=1e18;
		long long x;
		cin>>x;
		int hoge=lower_bound(s.begin(),s.end(),x)-s.begin();
		if(hoge==a){
			ans=min(ans,abs(s[hoge-1]-x)+nt[hoge-1]);
		}else if(hoge==0){
			ans=min(ans,abs(s[hoge]-x)+nt[hoge]);
		}else{
			ans=min(ans,abs(s[hoge]-x)+nt[hoge]);
			ans=min(ans,abs(s[hoge-1]-x)+nt[hoge-1]);
		}
		hoge=lower_bound(t.begin(),t.end(),x)-t.begin();
		if(hoge==b){
			ans=min(ans,abs(t[hoge-1]-x)+ns[hoge-1]);
		}else if(hoge==0){
			ans=min(ans,abs(t[hoge]-x)+ns[hoge]);
		}else{
			ans=min(ans,abs(t[hoge]-x)+ns[hoge]);
			ans=min(ans,abs(t[hoge-1]-x)+ns[hoge-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
