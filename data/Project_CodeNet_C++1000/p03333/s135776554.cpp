#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i=0; i<(long long)(n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
template<class T> bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}

int main(){
	int N; cin >> N;
	vector<int> L(N), R(N);
	rep(i, N) cin >> L[i] >> R[i];
	sort(all(L), greater<int>());
	sort(all(R));
	ll K = 0, s = 0;
	rep(i, N){
		chmax(K, s+L[i]);
		chmax(K, s-R[i]);
		chmax(K, s+L[i]-R[i]);
		s += L[i] - R[i];
	}
	cout << 2*K << endl;
	return 0;
}
