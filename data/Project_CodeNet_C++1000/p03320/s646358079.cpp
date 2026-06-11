#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

ll pow(ll a, ll n) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a) {
		if (n % 2LL == 1LL) {
			ret = ret * a;
		}
	}
	return ret;
}

int main() {
  ll K;
  cin>>K;
  ll ans = 0LL;
  ll cnt = 0LL;
  ll t = 0LL;
  while(cnt<K){
    ans = ans+ pow(10LL,t);
    ll a = (ans/pow(10LL,t+1LL))%10LL,b=(ans/pow(10LL,t+2))%10LL;
    if(9*t-1LL<9LL*a+99LL*b&&ans>9LL){
      ans-=pow(10LL,t);
      t++;
      ll c = pow(10LL,t)-1LL+(ans/pow(10LL,t))*pow(10LL,t);
      if(ans==c) c+=pow(10LL,t);
      ans=c;
    }
    cout<<ans<<endl;
    cnt++;
  }
}