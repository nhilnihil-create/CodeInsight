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

  int a, b, k;
  cin >> a >> b >> k;
  ll g = __gcd(a, b);
  int ans = 0, cnt = 0;
  for(ll i = g; i>= 1; i--){
  	if(g%i == 0){
  		ans = i;
  		cnt++;
  		if(cnt == k)break;
  	}
  }
  cout << ans << endl;

}


