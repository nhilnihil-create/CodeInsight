#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P; 
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

vector<int> v,u;
int a[2222];

int main(void){
	int n,i,j,k,m,q,ans=INF;
	cin >> n >> m >> q;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	for(i=0; i<=n; ++i){
		for(j=0; j<=n; ++j){
			if(a[j]>a[i]){
				v.push_back(a[j]);
				continue;
			}
			sort(v.begin(),v.end(),greater<int>());
			for(k=m-1; k<v.l_ength(); ++k){
				u.push_back(v[k]);
			}
			v.clear();
		}
		sort(u.begin(),u.end());
		if(u.l_ength()>=q){
			ans = min(ans,u[q-1]-u[0]);
		}
		u.clear();
	}
	cout << ans << endl;
	return 0;
}
