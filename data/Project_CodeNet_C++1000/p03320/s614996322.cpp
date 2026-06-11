#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
inline int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
inline int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
inline int mul(int a, int b) {return 1ll * a * b % P;}
inline int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
int n;
set<ll> nine;
bool gao(ll head, ll tail) {
	int s = 0;
	if(nine.count(head))
		return 1;
	ll t = tail;
	while(t) {
		s += t % 10;
		t /= 10;
	}
	t = head;
	while(t) {
		s += t % 10;
		t /= 10;
	}
	ll p = 1;
	t = head;
	while(t) {
		if(t % 10 != 9) break;
		p *= 10;
		t /= 10;
	}
	return p * (tail + 1) * s >= head * (tail + 1) + tail;
}
int main(){
	ll t = 0;
	rep(i, 0, 15) {
		t = t * 10 + 9;
		nine.insert(t);
	}
	scanf("%d", &n);
	int cnt = 0;
	ll tail = 0, head = 0;
	set<ll> ans; 
	rep(i, 0, 14) {
		rep(head, 1, 1000) {
			if(gao(head, tail))
				ans.insert(head * (tail + 1) + tail);
		}
		tail = tail * 10 + 9;
	}
	auto it = ans.begin();
	rep(i, 0, n) {
		printf("%lld\n", *it);
		it++;
	}
	return 0;
}
