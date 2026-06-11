#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
LL N,C;
typedef pair<LL,LL>P;
vector<P>v;
vector<P>rv;
LL ans[100001];
LL s[100001];

LL rans[100001];
LL rs[100001];
int main(){
	cin>>N>>C;
	REP(i,N){
		LL a,b;
		cin>>a>>b;
		v.push_back(P(a,b));
		rv.push_back(P(C-a,-b));
	}
	sort(v.begin(),v.end());
	sort(rv.begin(),rv.end());
	REP(i,N){
		ans[i]=0;
		if(i!=0){
			s[i]=v[i].second+s[i-1];
		}else{
			s[i]=v[i].second;
		}
	}
	REP(i,N){
		if(i==0){
			ans[i]=max(LL(0),s[i]-v[i].first);
		}else{
			ans[i]=max(ans[i-1],s[i]-v[i].first);
		}
	}
	
	REP(i,N){
		rans[i]=0;
		if(i!=0){
			rs[i]=(-1)*rv[i].second+rs[i-1];
		}else{
			rs[i]=(-1)*rv[i].second;
		}
	}
	REP(i,N){
		if(i==0){
			rans[i]=max(LL(0),rs[i]-rv[i].first);
		}else{
			rans[i]=max(rans[i-1],rs[i]-rv[i].first);
		}
	}
	
	LL aa=0;
	REP(i,N){
		aa=max(aa,rans[i]);
		aa=max(aa,ans[i]);
	}
	
	REP(i,N){
		aa=max(aa,s[i]-2*v[i].first+rans[N-1-i-1]);
		aa=max(aa,rs[i]-2*rv[i].first+ans[N-1-i-1]);
	}
	
	/*REP(i,N){
		cout<<s[i]<<" ri"<<ans[i]<<endl;
	}
	REP(i,N){
		cout<<rs[i]<<" le"<<rans[i]<<endl;
	}*/
	cout<<aa<<endl;
	
	return(0);
}