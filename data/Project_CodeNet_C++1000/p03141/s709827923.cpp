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
	vector<pair<ll,P>> sum(n);
	for(int i = 0; i < n; i++) {
		ll x,y;cin>>x>>y;
		sum[i] = mp(x + y,mp(x,y));
	}
	sort(ALL(sum),greater<pair<ll,P>> ());
	ll t = 0;
	ll a = 0;
	for(int i = 0; i < n; i++) {
		if(i % 2== 0){t += (sum[i].sc).fs;}
		else {a += (sum[i].sc).sc;}
	}
	cout << t - a << endl;
	return 0;
}