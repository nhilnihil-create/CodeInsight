#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n;
	string s, u;
	char c;
	ll x, y;
	cin >> n;
	ll ans = 0, btc = 0;
	forn(i, 0, n){
		cin >> s >> u;
		if(u == "BTC"){
			int m = s.size();
			y = stoll(s.substr(m-8, 8));
			x = stoll(s.substr(0, m-8-1));
			x = x*100000000+y;
			btc += x*380000;
		}else{
			x = stoll(s);
			ans += x;
		}
	}
	double r = btc;
	r /= 100000000;
	cout << r+ans << endl;
//380000 - 0.1 btc
//10000 - x

}


