#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
 
lli convert[26];
 
signed main(){
 
	string s,t;
	cin>>s>>t;
 
	map<char,lli> ss,tt;
	REP(i,0,s.size()){
		ss[s.at(i)]++;
		tt[t.at(i)]++;
	}
 
	multiset<lli> sC,tC;
	for(auto e:ss){
		sC.insert(e.second);
	}
 
	for(auto e:tt){
		tC.insert(e.second);
	}
 
	if(sC.size()!=tC.size()){
		cout<<"No"<<endl;
		return 0;
	}
	auto itr1 = sC.begin();
	auto itr2 = tC.begin();
 
	while(itr1!=sC.end()){
		if((*itr1)!=(*itr2)){
			cout<<"No"<<endl;
			return 0;
		}
		itr1++;
		itr2++;
	}
	cout<<"Yes"<<endl;
 
	return 0;
}