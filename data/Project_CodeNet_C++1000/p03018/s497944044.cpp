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
	string s;cin>>s;
	ll n = s.size();
	ll cnt = 0;
	ll ans = 0;
	ll i = 0;
	while(i < n) {
		if (s[i] == 'A'){
			cnt = 1;
			i++;
			while(i + 1 < n){
				if (s[i] == 'A'){
					cnt++;
					i++;
				}
				else if (s[i] == 'B' && s[i + 1] == 'C') {
					ans += cnt;
					i += 2;
				}
				else{
					break;
				}
			}
		}
		else {
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}