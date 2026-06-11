#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define ll long long
#define ld long double
#define MAX (int)(2*pow(10,5)+10)
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,9);
ll INF = inf;
ll modulo = pow(10,9)+7;
double eps = 1e-10;
ifstream in;
ofstream out;

vector<pair<char,char> > que;
vector<char> all;
string dir = "LR";
ll dif[2] = {-1, 1};

ll calc(ll ind){
//	cout<<"begin "<<ind<<endl;
	for(auto el: que){
		if(el.ff == all[ind]){
			ind+=dif[dir.find(el.ss)];
			if(ind<0 || ind >= all.size())
				break;
		}
//		cout<<ind<<endl;
	}
	return ind;
}

void deal(){
	ll n , q;
	cin>>n>>q;
	all.resize(n);
	fori(n)
		cin>>all[i];
	que.resize(q);
	fori(q)
		cin>>que[i].ff>>que[i].ss;
	ll ans = 0;
	if(calc(0) < 0){
		ll lo = 0, hi = n-1;
		while(lo < hi){
			ll mid = (lo+hi)/2+1;
			if(calc(mid) <0 )
				lo = mid;
			else
				hi = mid-1;
		}
		ans+=lo+1;
	}
	if(calc(n-1) > n-1){
		ll lo = 0, hi = n-1;
		while(lo < hi){
			ll mid = (lo+hi)/2;
			if(calc(mid) > n-1)
				hi = mid;
			else
				lo = mid+1;
		}
		ans+=((n-1)-lo)+1;
	}
	cout<<n-ans;
}



int main(){
//	test();
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}



/*
	
*/