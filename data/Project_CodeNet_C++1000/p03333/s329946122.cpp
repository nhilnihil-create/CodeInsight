#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
ll L[100100],R[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> L[i] >> R[i];
	}
	sort(L,L+N);
	reverse(L,L+N);
	sort(R,R+N);
	for(int i=0;i<N;i++){
		L[i+1] += L[i];
		R[i+1] += R[i];
	}
	int r = 0;
	ll ans = 0ll;
	for(int l=0;l<=N;l++){
		for(int r=max(0,l-1);r<=min(N,l+1);r++){
			ll a = (l==0)?0ll:L[l-1];
			ll b = (r==0)?0ll:R[r-1];
			ans = max(ans,2ll*a-2ll*b);
		}
	}
	cout << ans << endl;
	return 0;
}

