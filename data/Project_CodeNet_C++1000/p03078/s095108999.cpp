#include<bits/stdc++.h>
#define se second
#define fi first
#define pb push_back
#define cn cout<<"\n"
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

#define _ ios::sync_with_stdio(0); cin.tie(0);

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define vll vector<ll>
#define flush fflush(stdout)

const int INF = 1e8;
const ll MOD = 1e9 + 7;

using namespace std;


vll a, b, c;

int main(){
	_

	int t = 1;

	int x, y, z, k;
	ll aux;
	cin>>x>>y>>z>>k;

	priority_queue< tuple<ll, int, int> > p;

	rep(i, 0, x){
		cin>>aux;
		a.pb(aux);
	}

	rep(i, 0, y){
		cin>>aux;
		rep(j, 0, a.size())
			b.pb(aux + a[j]);
	}

	sort(allr(b));

	rep(i, 0, z){
		cin>>aux;
		c.pb(aux);
	}

	sort(allr(c));

	rep(i, 0, z)
		p.push(make_tuple(c[i] + b[0], i, 0));

	int i = 0, j = z - 1;
	while(i < k){

		tuple<ll, int, int> top = p.top(); p.pop();
		ll val = get<0>(top);
		int uu = get<1>(top);
		int vv = get<2>(top);

		cout<<val; cn;

		int next = vv + 1;

		if(next < b.size()) p.push(make_tuple(c[uu] + b[next], uu, next));
		
		i++;
	}


	return 0;
}