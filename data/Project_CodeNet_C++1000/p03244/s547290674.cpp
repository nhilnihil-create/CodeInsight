#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n;
map<int,int> mp1,mp2;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++){
		if(i%2) mp2[v[i]]++;
		else mp1[v[i]]++;
	}
	vector<pii> a,b;
	for(map<int,int>::iterator it=mp1.begin();it!=mp1.end();it++) a.pb(MP(it->se,it->fi));
	for(map<int,int>::iterator it=mp2.begin();it!=mp2.end();it++) b.pb(MP(it->se,it->fi));
	sort(rall(a));
	sort(rall(b));
	//for(int i=0;i<sz(a);i++) cout<<a[i].fi<<'-'<<a[i].se<<' ';
	int res;
	if(a[0].se==b[0].se){
		if(sz(a)==1&&sz(b)==1){
			cout<<n/2;
			re 0;
		}
		res=max(a[0].fi+b[1].fi,a[1].fi+b[0].fi);
	}
	else res=a[0].fi+b[0].fi;
	cout<<n-res;
	re 0;
}