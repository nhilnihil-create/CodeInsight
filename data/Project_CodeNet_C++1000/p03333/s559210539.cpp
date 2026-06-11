#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<ll, int> P;
#define MOD (1000000007ll)
#define l_ength size
#define EPS (1e-10)

ll l[123456],r[123456];
vector<P> lv,rv;

bool comp(P a, P b){
	return a.first > b.first;
}

priority_queue<P> pql,pqr;
bool used[100100];

int main(void){
	int n,i;
	P p;
	ll l,r,ans=-INFLL,tmp=0ll;
	bool flag=false;
	fill(used,used+100100,false);
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> l >> r;
		pql.push(P(l,i));
		pqr.push(P(-r,i));
	}
	while(true){
		while(true){
			if(pql.empty()){
				flag = true;
				break;
			}
			p = pql.top();
			if(used[p.second]){
				pql.pop();
				continue;
			}
			l = p.first;
			used[p.second] = true;
			pql.pop();
			ans = max(ans,tmp+l);
			break;
		}
		while(true){
			if(pqr.empty()){
				flag = true;
				break;
			}
			p = pqr.top();
			if(used[p.second]){
				pqr.pop();
				continue;
			}
			r = p.first;
			used[p.second] = true;
			pqr.pop();
			ans = max(ans,tmp+r);
			break;
		}
		if(flag){
			break;
		}
		tmp += (l+r);
		ans = max(ans,tmp);
	}
	cout << (ans*2) << endl;
	return 0;
}
