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

int n,a[225816];
stack<P> s;

bool addone(int p, int k){
	int v;
	if(p<1){
		return false;
	}
	while((!s.empty()) && s.top().first>p){
		s.pop();
	}
	if(s.empty()){
		s.push(P(p,1));
		return true;
	}
	if(s.top().first<p){
		s.push(P(p,1));
		return true;
	}
	v = s.top().second; ++v;
	if(v<k){
		s.pop();
		s.push(P(p,v));
		return true;
	}else{
		return addone(p-1,k);
	}
}

bool judge(int k){
	int i,p=0,m=n;
	if(k==0){
		return false;
	}else if(k==1){
		for(i=1; i<n; ++i){
			if(a[i-1]<a[i]){
				continue;
			}
			return false;
		}
		return true;
	}
	for(i=1; i<n; ++i){
		if(a[i-1]<a[i]){
			continue;
		}
		if(!addone(a[i],k)){
			return false;
		}
	}
	return true;
}

int main(void){
	int i,l,r,m;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	l = 0; r = n;
	while(r-l>1){
		m = (l+r)/2;
		while(!s.empty()){
			s.pop();
		}
		if(judge(m)){
			r = m;
		}else{
			l = m;
		}
	}
	cout << r << endl;
	return 0;
}
