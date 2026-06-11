#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<llint> make_divisors(llint x){
	vector<llint> div;
	for(llint i=1;i*i<=x;i++){
		if(x%i==0){
			div.push_back(i);
			if(x/i!=i)div.push_back(x/i);
		}
	}
	return div;
}

void solve(){
	llint n,m;
	cin >> n >> m;
	vector<llint>div=make_divisors(m);
	llint ans=0;
	for(auto d:div){
		if(d*n<=m)ans=max(ans,d);
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
