//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	//n頂点m枝に対して隣接リストをつくる。
	int n;
	cin >> n;
	int u, v;
	//vector< vector <int> > ls(n); //0-origin
	vector< vector <int> > ls(n+1); //1-origin
	REP(i, n-1){ 
		cin >> u >> v; 
		ls[u].push_back(v); 
		ls[v].push_back(u); //有向グラフならコメントアウトせよ
	}
	//
	priority_queue<ll> c;
	REP(i, n) {
		cin >> tmp;
		c.push(tmp);
	}
	ll num[n+1];
	queue<int> q;
	q.push(1);
	bool ch[n+1] ={};
	ch[1]= true;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		num[tmp] = c.top();
		if(tmp != 1) ans += c.top();
		c.pop();
		REP(i, ls[tmp].size()) {
			if(!ch[ls[tmp][i]]){
				ch[ls[tmp][i]]= true;
				q.push(ls[tmp][i]);
			}
		}
	}
	cout << ans << endl;
	REP1(i,n) cout << num[i] << " ";
	cout << endl;
}