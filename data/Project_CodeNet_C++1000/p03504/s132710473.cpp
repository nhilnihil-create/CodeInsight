#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

struct edge {
	ll ind;
	ll to;
	ll d;
};


///////////////////////////


int main() {

	ll N,C;
    cin >>N>>C;

    vector<vector<bool>> r(C+1,vector<bool>(MAX,0));

    repn(i,N){
        ll s,t,c;
        cin >>s>>t>>c;

        for(ll i=s; i<=t; i++){
            r[c][i]=1;
        }
    }

    ll ans=0;

    rep(i,MAX){
        ll v=0;
        repn(j,C){v+=r[j][i];}
        ans=max(ans,v);
        //if(v!=0)cout <<i<<v<<endl;
    }

    cout <<ans;

}
