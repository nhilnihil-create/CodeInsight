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

  int n, a, b;
  string s;

  cin >> n >> a >> b;

  ll ans = 0;

  forn(i, 1, n+1){
	  s = to_string(i);
		int sum = 0;
	  for(auto c: s){
			sum += c-'0';
	  }
		if(sum >= a && sum <= b)ans += i;
  }

	cout << ans << endl;




}


