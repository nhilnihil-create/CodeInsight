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
	int ans = 0;
	int tmp;
	vector<ll> sh;
	queue<ll> q;
	q.push(3);
	q.push(5);
	q.push(7);
	while(!q.empty()){
		ll he = q.front();
		q.pop();
		set<char> se;
		se.clear();
		string st = to_string(he);
		REP(i, st.size()) se.insert(st[i]);
		if(se.size() == 3)sh.push_back(he);
		if(he * 10 < 1000000000){
			q.push(he * 10 + 3);
			q.push(he * 10 + 5);
			q.push(he * 10 + 7);
		}
	}
	ll n;
	cin >> n;
	auto it = upper_bound(sh.begin(), sh.end(), n);
	cout << it - sh.begin() << endl;
}