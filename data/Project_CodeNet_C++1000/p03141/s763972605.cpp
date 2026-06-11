#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<ll,ll>> p;
	vector<ll> A(N),B(N);
	rep(i,N){
		ll a,b,c;
		cin >> a >> b;
		A[i] = a;
		B[i] = b;
		c = a + b;
		p.emplace_back(-c,i);
	}
	ll ans = 0;
	sort(ALL(p));
	rep(i,N){
		if(i%2==0)ans += A[p[i].second];
		else ans -= B[p[i].second];
	}
	cout << ans << endl;
}