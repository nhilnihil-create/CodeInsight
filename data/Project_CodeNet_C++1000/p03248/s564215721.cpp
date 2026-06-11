//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	//int n; cin >> n;
	string s; cin >> s;
	int n = s.size();
	s = "0" + s;
	bool ch = true;
	REP1(i, n-1) if(s[i] != s[n-i]) ch = false;
	if(s[n] == '1') ch = false;
	if(s[1] == '0') ch = false;
	if(ch){
		queue<int> q;
		REP1(i, n/2) if(s[i] == '1') q.push(i);
		int ed = 1, now = 0, root = 1, prev = 0;
		while(!q.empty()){
			now = q.front();
			q.pop();
			REP(i, now - prev){
				cout << root << " " << ed + 1 << endl;
				ed++;
			}
			root = ed;
			prev = now;
		}
		while (ed < n)
		{
			cout << root << " " << ed + 1 << endl;
			ed++;
		}
		
	}
	else cout << -1 << endl;
}