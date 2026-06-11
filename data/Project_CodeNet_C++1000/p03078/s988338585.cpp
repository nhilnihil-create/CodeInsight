#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vector<ll> a,b,c;
int main(void){
	ll x,y,z,k;
	cin>>x>>y>>z>>k;
	a = vi(x);
	b = vi(y);
	c = vi(z);
	for(int i = 0; i <x; i++){
		cin>>a[i];
	}
	for(int i = 0; i < y; i++){
		cin>>b[i];
	}
	for(int i = 0; i < z; i++){
		cin>>c[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	sort(b.begin(), b.end(), greater<ll>());
	sort(c.begin(), c.end(), greater<ll>());
	priority_queue<vi> q;
	q.push(vi({a[0] + b[0] + c[0], 0, 0, 0}));
	set<vi> seen;
	while(k--){
		vi t = q.top(); q.pop();
		cout<<t[0]<<'\n';
		int ai = t[1], bi = t[2], ci = t[3];
		vi tt(4);
		vi ttt(3);
		if(ai + 1 < x){
			ttt[0] = ai + 1;
			ttt[1] = bi;
			ttt[2] = ci;
			if(!seen.count(ttt)){
				seen.insert(ttt);
				tt[0] = t[0] - a[ai] + a[ai+1];
				tt[1] = ai + 1;
				tt[2] = bi;
				tt[3] = ci;
				q.push(tt);
			}
		}
		if(bi + 1 < x){
			ttt[1] = bi + 1;
			ttt[0] = ai;
			ttt[2] = ci;
			if(!seen.count(ttt)){
				seen.insert(ttt);
				tt[0] = t[0] - b[bi] + b[bi+1];
				tt[2] = bi + 1;
				tt[1] = ai;
				tt[3] = ci;
				q.push(tt);
			}
		}
		if(ci + 1 < x){
			ttt[2] = ci + 1;
			ttt[0] = ai;
			ttt[1] = bi;
			if(!seen.count(ttt)){
				seen.insert(ttt);
				tt[0] = t[0] - c[ci] + c[ci+1];
				tt[3] = ci + 1;
				tt[2] = bi;
				tt[1] = ai;
				q.push(tt);
			}
		}
	}
	return 0;
}
