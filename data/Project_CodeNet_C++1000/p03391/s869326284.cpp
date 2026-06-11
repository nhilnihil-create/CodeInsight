#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

#define P pair<lli,lli>

struct d{
	lli x,y;
	bool operator<(const d& right)const{
		if( (this->y-this->x) != (right.y-right.x) ){
			return this->y-this->x > right.y-right.x;
		}
		else{
			return this->y > right.y;
		}
	}
};

signed main(){

	lli n;
	cin>>n;

	vector<lli> a(n),b(n);
	vector<d> c;

	lli ans = 0;
	bool flag=true;
	vector<lli> dd;
	REP(i,0,n){
		cin>>a[i]>>b[i];
		if(a[i]!=b[i])flag=false;

		if(b[i]>=a[i])c.push_back({a[i],b[i]});
		else dd.push_back(b[i]);
	}
	if(flag){
		cout<<0<<endl;
		return 0;
	}
	lli left=0;

	sort(c.begin(),c.end());
	sort(dd.rbegin(),dd.rend());
	
	REP(i,0,c.size()){
		if(DEBUG)cout<<"cx="<<c[i].x<<" cy="<<c[i].y<<" left="<<left<<endl;
		ans += c[i].y;
	}

	REP(i,0,dd.size()-1){
		ans+=dd[i];
	}
	
	/*
	REP(i,0,n){
		if(DEBUG)cout<<"cx="<<c[i].x<<" cy="<<c[i].y<<" left="<<left<<endl;
		if(c[i].y+left>c[i].x){
			ans += c[i].x;
			left = c[i].y+left-c[i].x;
		}
		else break;
	}*/
	cout<<ans<<endl;



	return 0;
}