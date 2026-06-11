#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef pair<int,int> P;

int main(){
	ll N,H;
	cin >> N >> H;
	ll ma = 0;
	vector<ll> A;
	vector<ll> B;
	rep(i,N){
		ll a,b;
		cin >> a >> b;
		A.push_back(a); B.push_back(b);
	}
	ma = *max_element(A.begin(),A.end());
	ll ans = 0;
	sort(B.begin(),B.end());
	reverse(B.begin(),B.end());
	for(ll u : B){if(u>ma){H-=u; ans++; if(H<=0)break;}}
	if(H>0){
		ans += H/ma;
		if( H%ma )ans++;
	}
	cout << ans << endl;

	return 0;
}


