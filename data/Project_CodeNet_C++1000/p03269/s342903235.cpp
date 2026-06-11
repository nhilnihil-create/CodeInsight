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
  ll L;
  cin>>L;
  ll s = L;
  ll cnt = 0LL;
  vector<ll> v;
  ll edge = 0LL;
  while(s!=0){
    edge+=s%3;
    v.push_back(s%3LL);
    s=s/3;
    cnt++;  
  }
  cout<<cnt+1<<" "<<(cnt-1)*3+edge<<endl;
  ll num = 1LL;
  for(ll i = 0LL; i < cnt-1; i++){
    cout<<i+1<<" "<<i+2<<" "<<0<<endl;
    cout<<i+1<<" "<<i+2<<" "<<num<<endl;
    cout<<i+1<<" "<<i+2<<" "<<num*2LL<<endl;
    num*=3;
  }
  ll total = 0LL;
  for(ll i = 0LL; i < cnt; i++){
    if(v[i]==1) {
      cout<<i+1<<" "<<cnt+1<<" "<<total<<endl;
      total+=pow(3,i);
    }
    if(v[i]==2){
      cout<<i+1<<" "<<cnt+1<<" "<<total<<endl;
      total+=pow(3,i);
      cout<<i+1<<" "<<cnt+1<<" "<<total<<endl;
      total+=pow(3,i);
    }
  }
}