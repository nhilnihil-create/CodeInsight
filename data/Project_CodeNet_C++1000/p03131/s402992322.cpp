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
	ll k,a,b;cin>>k>>a>>b;
	ll ans = k + 1;
	if ( a < b){
		ll tmp = 1;
		if (k > a){
			tmp += a - 1;
			k -= a - 1;
			tmp += (k / 2) * (b - a);
			if (k % 2 == 1){
				tmp++;
			}
		}
		ans = max(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}