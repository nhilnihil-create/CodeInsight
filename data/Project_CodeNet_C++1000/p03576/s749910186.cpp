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
	int n,K;cin>>n>>K;
	ll A,B;
	vector<P> a(n);
	for(int i = 0; i < n; i++) {
		cin>>A>>B;
		a[i] = mp(A,B);
	}
	ll ans = 5 * LINF;
	for(int i = 0; i < n; i++) {
		ll x1 = a[i].fs,y1 = a[i].sc;
		for(int j = 0; j < n; j++) {
			ll x2 = a[j].fs,y2 = a[j].sc; 
			for(int k = 0; k < n; k++) {
				ll x3 = a[k].fs,y3 = a[k].sc;
				for(int l = 0; l < n; l++) {
					ll x4 = a[l].fs,y4 = a[l].sc;
					ll x_min = min(x1,min(x2,min(x3,x4)));
					ll x_max = max(x1,max(x2,max(x3,x4)));
					ll y_min = min(y1,min(y2,min(y3,y4)));
					ll y_max = max(y1,max(y2,max(y3,y4)));
					int count = 0;
					for(int m = 0; m < n; m++) {
						if(a[m].fs >= x_min && a[m].fs <= x_max && a[m].sc >= y_min && a[m].sc <= y_max){
							count++;
						}
					}
					if(count >= K){
						// cout << count << endl;
						// cout << x_max << " " << x_min << " " << y_max << " " << y_min << endl;
						ans = min(ans,(abs(x_max - x_min) * abs(y_max - y_min)));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}