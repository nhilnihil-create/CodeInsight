#include <bits/stdc++.h>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Pos(i) cout<<(i?"Possible":"Impossible")<<endl
#define co(i) cout<<i<<endl
#define fcout cout<<fixed<<setprecision(10)
using namespace std;
//
const int INF=1e9+7;
const int MOD=1e9+7;
//
int ketawa(ll k,int a){
	if(k) return k%a+ketawa(k/a,a);
	else return 0;
}

ll beki(int k){
	ll ans=1;
	FOR(i,0,k) ans*=10;
	return ans;
}

int main(){
	vector<ll> v;
	int k; cin>>k;
	FOR(i,0,16){
		FOR(j,0,1000){
			if(j*beki(i)+beki(i)-1<=10e15)
			v.PB(j*beki(i)+beki(i)-1);
		}
	}
	sort(v.rbegin(),v.rend());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<ll> snuke;
	double m=10e17;
	FOR(i,0,v.size()-1){
		if(v[i]<=m*ketawa(v[i],10)){
			snuke.PB(v[i]);
			m=(double)v[i]/ketawa(v[i],10);
		}
	}
	FOR(i,0,k){
		co(snuke[snuke.size()-1-i]);
	}
}
