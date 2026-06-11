#include<bits/stdc++.h>
using namespace std;
#define maxn 100020
#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pr;

set <ll> s;
set <ll>::iterator it;
int k;
ll pow_[20];

void init(){
	int a[28] = {0,1,2,3,4,5,6,7,8,9,19,29,39,49,59,69,79,89,99,199,299,399,499,599,699,799,899,999};
	rep(i,1,27) s.insert(a[i]);
	pow_[0] = 1;
	rep(i,1,18) pow_[i] = pow_[i - 1] * 10;
}
int cal(ll n){
	int res = 0;
	while ( n ) res += n % 10 , n /= 10;
	return res;
}
bool check(ll a,ll b){
	return a * cal(b) <= b * cal(a);
}
void expand(ll cur,int id){
	rep(i,1,9){
		ll x = cur - pow_[id];
		if ( !check(x,cur) ) return;
		s.insert(cur = x);
	}
	if ( id > 2 ) expand(cur,id - 1);
}
void solve(){
	if ( k <= s.size() ){
		int cnt = 1;
		for ( it = s.begin() ; cnt <= k ; cnt++ , it++){
			printf("%lld\n",(*it));
		}
		return;
	}
	rep(i,3,14){ //10^3 - 10^15
		rep(j,1,9){ //the front number , 19999 is legal
			s.insert(pow_[i] * (j + 1) - 1);
			expand(pow_[i] * (j + 1) - 1,i - 1);
		}
		if ( k <= s.size() ){
			int cnt = 1;
			for ( it = s.begin() ; cnt <= k ; cnt++ , it++){
				printf("%lld\n",(*it));
			}
			return;
		}
	}
}
int main(){
	init();
	cin>>k;
	solve();
}
