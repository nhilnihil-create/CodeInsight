#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n;cin>>n;
	string s;cin>>s;
	ll cnt1 = 0;
	ll cnt2 = 0;

	for(ll i = 0; i < n; i++) {
		if (s[i] == '.')cnt1++;
	}
	ll ans = LINF;
	for(int i = 0; i < n; i++) {
		if (s[i] == '.'){
			ans = min(ans,cnt1 + cnt2);
			cnt1--;
		}
		else{
			ans = min(ans,cnt1 + cnt2);
			cnt2++;
		}
	}
	ans = min(ans,cnt2);
	cout << ans << endl;
	return 0;
}