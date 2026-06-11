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
	ll sum = 0;
	int r = 0;
	ll ans = 0;
	for(int l = 0; l < n; l++) {
		while(((sum ^ a[r]) == (sum + a[r])) && (r < n)){
			sum += a[r];
			r++;
		}
		ans += (r - l);
		if (l == r){//左が右を追い越さない
			r++;
		}
		else{//左端を削除
			sum -= a[l];
		}
	}
	cout << ans << endl;
	return 0;
}