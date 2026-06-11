#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
#define MOD (1000000007ll)
#define l_ength size
#define PI 3.14159265358979

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

ll dist[123456];
deque<int> dq;

int main(void){
	int k,v,x,y;
	cin >> k;
	fill(dist,dist+k,INFLL);
	dist[1] = 1ll;
	dq.push_front(1);
	while(!dq.empty()){
		v = dq.front();
		x = (v+1)%k;
		y = (v*10)%k;
		dq.pop_front();
		if(dist[x] > dist[v] + 1ll){
			dist[x] = dist[v] + 1ll;
			dq.push_back(x);
		}
		if(dist[y] > dist[v]){
			dist[y] = dist[v];
			dq.push_front(y);
		}
	}
	cout << dist[0] << endl;
	return 0;
}
