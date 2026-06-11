#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n,l[101001]={},r[101010]={};
	cin>>n;
	priority_queue<pair<pair<int,int>,int>> pq;//lでかい順 l,r,idx
	priority_queue<pair<pair<int,int>,int>> pq2;//r小さい順 -r,l,idx
	map<pair<int,int>,int> mp;
	LL ans=0LL;

	FOR(i,0,n){
		cin>>l[i]>>r[i];
		pq.push(MP(MP(l[i],r[i]),i));
		pq2.push(MP(MP(-r[i],l[i]),i));
		mp[MP(l[i],r[i])]++;
	}
	int nx=0,c=0;
	while(!pq.empty()||!pq.empty()){
		pair<pair<int,int>,int> pr=MP(MP(0,0),mod);
		pair<pair<int,int>,int> pr2=MP(MP(0,0),mod);
		int ll,rr;
		while(!pq.empty()){
			pair<pair<int,int>,int> prt=pq.top();
			pq.pop();
			ll=prt.ST.ST;rr=prt.ST.ND;
			if(mp[MP(ll,rr)]>=1){
				mp[MP(ll,rr)]--;
				pr=prt;
				break;
			}
		}
		if(pr.ND==mod)break;
		int ll2,rr2;
		while(!pq2.empty()){
			pair<pair<int,int>,int> prt=pq2.top();
			pq2.pop();
			ll2=prt.ST.ND,rr2=-prt.ST.ST;
			if(mp[MP(ll2,rr2)]>=1){
				mp[MP(ll2,rr2)]--;
				pr2=prt;
				break;
			}
		}
		//if(pr2.ND==mod)break;
		if(c==0&&nx>=ll)break;
		if(nx<ll){ans+=ll-nx;nx=ll;}
		else if(nx>rr){ans+=nx-rr;nx=rr;}
		if(pr2.ND!=mod&&nx>rr2){ans+=nx-rr2;nx=rr2;}
		else if(pr2.ND!=mod&&nx<ll2){ans+=ll2-nx;nx=ll2;}

		c++;
		//cerr<<nx<<" "<<ll<<" "<<rr<<" "<<ll2<<" "<<rr2<<" "<<ans<<endl;

	}
	if(nx>=0)ans+=nx;
	else ans+=-nx;
	LL tmpans=ans;
	if(1){
		priority_queue<pair<pair<int,int>,int>> pq;//lでかい順 l,r,idx
		priority_queue<pair<pair<int,int>,int>> pq2;//r小さい順 -r,l,idx
		map<pair<int,int>,int> mp;
		ans=0LL;

		FOR(i,0,n){
			pq.push(MP(MP(l[i],r[i]),i));
			pq2.push(MP(MP(-r[i],l[i]),i));
			mp[MP(l[i],r[i])]++;

		}
		nx=0;
		while(!pq.empty()||!pq.empty()){
			pair<pair<int,int>,int> pr=MP(MP(0,0),mod);
			pair<pair<int,int>,int> pr2=MP(MP(0,0),mod);
			int ll2,rr2;
			while(!pq2.empty()){
				pair<pair<int,int>,int> prt=pq2.top();
				pq2.pop();
				ll2=prt.ST.ND,rr2=-prt.ST.ST;
				if(mp[MP(ll2,rr2)]>=1){
					mp[MP(ll2,rr2)]--;
					pr2=prt;
					break;
				}
			}
			if(pr2.ND==mod)break;
			int ll,rr;
			while(!pq.empty()){
				pair<pair<int,int>,int> prt=pq.top();
				pq.pop();
				ll=prt.ST.ST;rr=prt.ST.ND;
				if(mp[MP(ll,rr)]>=1){
					mp[MP(ll,rr)]--;
					pr=prt;
					break;
				}
			}
			//if(pr.ND==mod)break;
			if(nx>rr2){ans+=nx-rr2;nx=rr2;}
			else if(nx<ll2){ans+=ll2-nx;nx=ll2;}
			if(pr.ND!=mod&&nx<ll){ans+=ll-nx;nx=ll;}
			else if(pr.ND!=mod&&nx>rr){ans+=nx-rr;nx=rr;}


		}
	}
	if(nx>=0)ans+=nx;
	else ans+=-nx;
	ans=max(ans,tmpans);

	//cerr<<nx<<endl;
	cout<<ans<<endl;
    return 0;
}
