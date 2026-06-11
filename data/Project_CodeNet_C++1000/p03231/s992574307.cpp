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
	ll n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	ll gcd = __gcd(n,m);
	ll lcm = n / gcd * m;
	for(ll i = 0; i < gcd; i++) {
		if (s[n / gcd * i] != t[m / gcd * i]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << lcm << endl;

	return 0;
}