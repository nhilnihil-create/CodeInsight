#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i=0; i<(long long)(n); i++)
#define REP(i, k, n) for(long long i=(long long)(k); i<(long long)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define PQ(T) priority_queue<T>
#define PQS(T) priority_queue<T, vector<T>, greater<T> >
#define deci cout << fixed << setprecision(15);
typedef long long ll;
const ll inf = 1020304050607080910;
const int mod = 1000000007;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
ll gcd(ll x,ll y){if(x>y)swap(x, y);while(x!=0){y%=x;swap(x, y);}return y;}
ll mpow(ll x,ll r){if(r==0)return 1;if(r%2==1){return x*mpow(x,r-1)%mod;}else{ll aa=mpow(x,r/2);return aa*aa%mod;}}

int main(){
	int N; cin >> N;
	vector<P> L(N), R(N);
	rep(i, N){
		cin >> L[i].first >> R[i].first;
		L[i].second = i, R[i].second = i;
	}
	sort(all(L), greater<P>());
	sort(all(R));
	ll K = 0, s = 0;
	rep(i, N){
		if(L[i].first <= R[i].first){
			chmax(K, s+L[i].first);
			chmax(K, s-R[i].first);
		}else{
			s += L[i].first - R[i].first;
			chmax(K, s);
			chmax(K, s+R[i].first);
			chmax(K, s-L[i].first);
		}
	}
	cout << 2*K << endl;
	return 0;
}
