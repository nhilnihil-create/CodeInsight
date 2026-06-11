#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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

vector<int> v[225816];
priority_queue<int, vector<int>, greater<int> > pq;

int main(void){
	int h,w,n,i,j,x,y,ans,r=0;
	cin >> h >> w >> n;
	ans = h;
	for(i=0; i<n; ++i){
		cin >> x >> y; --x; --y;
		v[y].push_back(x);
	}
	for(i=0; i<w; ++i){
		v[i].push_back(h);
		sort(v[i].begin(),v[i].end());
	}
	for(j=(v[0].l_ength()-1); j>=0; --j){
		if(v[0][j]>0){
			pq.push(v[0][j]);
		}
	}
	for(i=0; i<h; ++i){
		if(pq.top()==i){
			ans = i;
			break;
		}
		if(!((!v[r+1].l_ength()) || (upper_bound(v[r+1].begin(),v[r+1].end(),i+1)-lower_bound(v[r+1].begin(),v[r+1].end(),i+1)))){
			++r;
			for(j=(v[r].l_ength()-1); j>=0; --j){
				if(v[r][j]>i){
					pq.push(v[r][j]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
