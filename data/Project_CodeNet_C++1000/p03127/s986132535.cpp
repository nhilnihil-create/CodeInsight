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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int n;cin>>n;
	ll ans;
	for(int i = 0; i < n; i++) {
		ll a;cin>>a;
		if(i == 0){
			ans = __gcd(a,a);
		}
		else{
			ans = __gcd(ans,a);
		}
	}
	cout << ans << endl;
	return 0;
}