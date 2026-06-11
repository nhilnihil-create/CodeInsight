#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b)   for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)  for(int i = (a); i > (b); --i)
#define rep(i, n)      for(int i = 0; i < (n); ++i)
#define all(c)         begin(c), end(c)
#define rall(c)        rbegin(c), rend(c)
#define SZ(a)          ((ll) a.size())

typedef long long ll;
typedef unsigned long long ull;


int main(){
	ll N,K;
	cin >> N >> K;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	vector<ll> count(N+1,0);
	rep(i,N) count[A[i]]++;
	ll tmp=0;
	rep(i,N+1){
		if(count[i]>0) tmp++;
	}
	sort(all(count));
	ll ans=0;
	ll i=0;
	while(tmp>K){
		if(count[i]>0){
			ans+=count[i];
			tmp--;
		}
		i++;
	}
	printf("%lld",ans);
  return 0;
}
