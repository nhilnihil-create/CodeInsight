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

signed main(){

	lli h,w,n;
	cin>>h>>w>>n;
	lli sr,sc;
	cin>>sr>>sc;

	sr--,sc--;

	string s,t;
	cin>>s>>t;

	//左右
	lli nowL = -1,nowR = w;
	for(lli i=s.size()-1;i>=0;i--){
		//青木君落とされないようにするぞ
		if(t.at(i)=='L')nowR = min(nowR+1,w);
		if(t.at(i)=='R')nowL = max(nowL-1,-1LL);

		//高橋君落としに行くぞ
		if(s.at(i)=='L')nowL = min(nowL+1,h);
		if(s.at(i)=='R')nowR = max(nowR-1,-1LL);

		if(nowL+1>=nowR){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(sc<=nowL || nowR<=sc){
		cout<<"NO"<<endl;
		return 0;
	}

	nowL = -1,nowR = h;
	for(lli i=s.size()-1;i>=0;i--){
		//青木君落とされないようにするぞ

		if(t.at(i)=='U')nowR = min(nowR+1,h);
		if(t.at(i)=='D')nowL = max(nowL-1,-1LL);

		//高橋君落としに行くぞ
		if(s.at(i)=='U')nowL = min(nowL+1,h);
		if(s.at(i)=='D')nowR = max(nowR-1,-1LL);

		if(nowL+1>=nowR){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(sr<=nowL || nowR<=sr){
		cout<<"NO"<<endl;
		return 0;
	}

	cout<<"YES"<<endl;


	return 0;
}