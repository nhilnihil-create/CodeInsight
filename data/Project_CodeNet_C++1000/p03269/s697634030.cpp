#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 1e6 + 7;

struct Edge{
	int u, v, w;

	Edge(){
		u = v = w = 0;
	}

	Edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

int x, cnt = 0, bit[22];
vector <Edge> sv;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> x;
	x--;
	int tmp = x;
	while(tmp > 0){
		bit[++cnt] = tmp % 2;
		tmp /= 2;
	}
	for(int i = 1; i < cnt; i++){
		sv.pb(Edge(i, i + 1, 0));
		sv.pb(Edge(i, i + 1, 1 << (i - 1)));
	}
	int now = (1 << (cnt - 1));
	for(int i = cnt - 1; i >= 1; i--){
		if(i == 1){
			sv.pb(Edge(i, cnt, now));
			if(bit[i] == 1) sv.pb(Edge(i, cnt, now + 1));
		}
		else if(bit[i] == 1){
			sv.pb(Edge(i, cnt, now));
			now += (1 << (i - 1));
		}
	}
	if(x == 1) cnt = 2, sv.pb(Edge(1, 2, 0)), sv.pb(Edge(1, 2, 1));
	cout << cnt << " " << (int)sv.size() << "\n";
	for(auto p : sv){
		cout << p.u << " " << p.v << " " << p.w << "\n";
	}
}
