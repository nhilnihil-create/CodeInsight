#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e18+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll H,W,D;
P A[90005];
map<P,ll> cost;
ll Q;

ll calc(ll a1,ll a2){
	ll x=A[a1].second;
	ll y=A[a1].first;
	ll i=A[a2].second;
	ll j=A[a2].first;
	return abs(x-i)+abs(y-j);
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>H>>W>>D;

rep(h,H){
	rep(w,W){
		ll a;
		cin>>a;
		A[a].first=h+1;
		A[a].second=w+1;
	}
}

rep(i,D){
	ll to=i+1;
	while(1){
		if(to>D){
			P p1={i+1,to},p2{i+1,to-D};
			cost[p1]=cost[p2]+calc(to-D,to);
		}
		to+=D;
		if(to>H*W) break;
	}
}

cin>>Q;
rep(i,Q){
	ll L,R,d;
	cin>>L>>R;
	d=L%D;
	if(d==0) d=D;
	P p1={d,R},p2{d,L};
	cout<<cost[p1]-cost[p2]<<endl;
}


}
	
