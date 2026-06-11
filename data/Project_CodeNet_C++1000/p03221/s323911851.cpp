#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" ";
#define LOGE if(DEBUG)cout<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vector<lli> d[100100];

void func(lli now){
	printf("%06d",now);
}

int main(){

	lli n,m;
	cin>>n>>m;
	vector<lli> p(m),y(m);
	REP(i,0,m){
		cin>>p[i]>>y[i];
		d[p[i]].push_back(y[i]);
	}

	REP(i,0,100100){
		if(d[i].size()==0)continue;
		SORT(d[i]);
	}

	REP(i,0,m){
		vector<lli> &v = d[p[i]];
		lli cnt = (lli)(lower_bound(v.begin(),v.end(),y[i]) - v.begin());
		func(p[i]);
		func(cnt+1);
		cout<<endl;
	}


    return 0;
}
