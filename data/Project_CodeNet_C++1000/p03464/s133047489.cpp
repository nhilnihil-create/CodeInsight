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
	int k;cin>>k;
	vector<ll> a(k);
	for(int i = 0; i < k; i++) {
		cin>>a[i];
	}
	ll l = 2,r = 2;
	for(int i = k - 1; i >= 0; i--) {
		if ((l + a[i] - 1) / a[i] * a[i] >= l && (l + a[i] - 1) / a[i] * a[i] <= r){
			l = (l + a[i] - 1)/ a[i] * a[i];
			r = (r / a[i]) * a[i] + a[i] - 1;
		}
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << " " << r << endl;
	return 0;
}