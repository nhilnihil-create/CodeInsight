#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 100000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
struct edge { int to, cost; };

//sは初めの点、vは頂点size、dは最短距離を求める(初期化はINF),Gは有向グラフ
void dijkdtra(int s,int v,vector<int>&d,whei(edge)&G) {
	priority_queue<Pint, vector<Pint>, greater<Pint>> que;//firstが距離、secondが頂点
	d[s] = 0;//スタートの距離はもちろんzero
	que.push(Pint(0, s));
	while (!que.empty()) {
		Pint p = que.top();
		que.pop();
		int V = p.second;
		if (d[V] < p.first)continue;
		for (int i = 0; i < G[V].size();i++) {
			edge e = G[V][i];
			if (d[e.to] > d[V] + e.cost) {
				d[e.to] = d[V] + e.cost;
				que.push(Pint(d[e.to], e.to));
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	hei(llint) s(n + 1,0);
	rep(i, 0, n) {
		llint a;
		cin >> a;
		s[i + 1] = s[i] + a;
	}
	sort(s.begin(), s.end());
	llint ans = 0;
	llint x = 1;
	s.push_back(INF);
	rep(i, 0, n+1) {
		if (s[i] == s[i + 1])x++;
		else {
			ans += (x * (x - 1)) / 2;
			x = 1;
		}
	}

	cout << ans << endl;
	return 0;
}