#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Pll;
typedef pair<P,P> PP;
#define rep(i,a,n) for(int i = a;i < n;i++)
#define LINF (ll)1e17
#define INF (int)1e9
#define MOD (ll)1e9+7
#define sMOD 1e5
#define fs first
#define sc second

ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}

void YNout(bool check){
	if(check)cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main(){
	ll n,cnt = 0;
	string s;
	
	cin >> n >> s;
	
	rep(i,0,n)if(s[i] == 'R')cnt++;
	
	YNout(cnt > n-cnt);
	return 0;

}
