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
	int n;cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	vector<ll> s(n + 1,0);
	for(int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}
	map<ll,ll> m;
	for(int i = 0; i < n + 1; i++) {
		m[s[i]]++;
	}
	ll ans = 0;
	for(auto& e:m){
		ans += e.sc * (e.sc - 1) /2;
	}
	cout << ans << endl;
	return 0;
}