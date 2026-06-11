#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair< int, int > Pi;
typedef pair< long long, long long > P;
typedef pair< long long, P > PP;
typedef pair< P, P > PPP;

const long long MOD = 1e9 + 7;
const long long INF = 5e18;
const int di[4] = { 1,0,-1,0 };
const int dj[4] = { 0,1,0,-1 };

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()

ll n,rui[1000010],mc[1000010],mm[1000010];
string s;
ll q,k;

void input(){
	cin>>n>>s>>q;
  for(int i=0;i<s.size();i++){
			if(s[i]=='C')rui[i+1]=rui[i]+1;
			else rui[i+1]=rui[i];
			if(s[i]=='M')mm[i+1]=mm[i]+1;
			else mm[i+1]=mm[i];
		}
		for(int i=0;i<s.size();i++){
			if(s[i]=='M')mc[i+1]=mc[i]+rui[i+1];
			else mc[i+1]=mc[i];
		}
	return;
}


void solve(){
	while(q--){
		cin>>k;
		ll ans=0;	
		for(ll i=0;i<s.size();i++){
			if(s[i]!='D')continue;
			int nex=min(n-1,i+k-1);
			ll t=(mm[nex+1]-mm[i+1])*rui[nex+1];
			t-=mc[nex+1]-mc[i+1];
			ans+=t;
		}
		cout<<ans<<endl;
	}
	return;
}

int main(){
	input();
	solve();
	return 0;
}
