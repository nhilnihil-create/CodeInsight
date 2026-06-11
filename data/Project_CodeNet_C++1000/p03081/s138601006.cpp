#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

using pchar = pair<char,char>;

lli data[200100];

lli simulate(const string &s,const vector<pchar> &td,int pos){
	for(auto c:td){
		if(s[pos]!=c.first)continue;
		if(c.second =='L')--pos;
		else ++pos;
		if(pos<0)return -1;
		if(pos>=(int)s.size())return 1;
	}
	return 0;
}

int solve(int N,const string&s, const vector<pchar> &td){
	lli low = -1, high=N;
	while(high-low>1){
		lli mid =(low+high)/2;
		if(simulate(s,td,mid)==-1)low=mid;
		else high = mid;
	}
	lli left_fall = high;

	low = -1,high=N;
	while(high-low>1){
		lli mid = (low+high)/2;
		if(simulate(s,td,mid)==1)high = mid;
		else low=mid;
	}
	lli right_fall = N-1-low;

	return N-(left_fall + right_fall);
}

signed main(){

	lli N,Q;string s;cin>>N>>Q>>s;
	vector<pchar> td(Q);
	for(lli i=0;i<Q;i++)cin>>td[i].first>>td[i].second;

	cout<<solve(N,s,td)<<endl;

	return 0;
}